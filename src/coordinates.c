
#include "coordinates.h"

#include "time.h"
#include "utils.h"

#include <math.h>


void transform_equatorial_to_ecliptical_coord(EquatorialCoord_TypeDef eqCoord, EclipticalCoord_TypeDef* ecCoord)
{
  // Initialize variables
  double x, y, sin_B, lon, lat;

  // Calculate ecliptical longitude (13.1)
  y = sin(HOUR_TO_RAD(eqCoord.right_ascension)) * cos(OBL_ECL_2000_RAD) + tan(DEG_TO_RAD(eqCoord.declination)) * sin(OBL_ECL_2000_RAD);
  x = cos(HOUR_TO_RAD(eqCoord.right_ascension));

  lon = rad_to_360(atan2(y, x));

  // Calculate ecliptical latitude (13.2)
  sin_B = sin(DEG_TO_RAD(eqCoord.declination)) * cos(OBL_ECL_2000_RAD) - cos(DEG_TO_RAD(eqCoord.declination)) * sin(OBL_ECL_2000_RAD) * sin(HOUR_TO_RAD(eqCoord.right_ascension));

  lat = rad_to_180(asin(sin_B));

  ecCoord->longitude = lon;
  ecCoord->latitude = lat;
}

void transform_ecliptical_to_equatorial_coord(EclipticalCoord_TypeDef ecCoord, EquatorialCoord_TypeDef* eqCoord)
{
  // Initialize variables
  double x, y, sin_dec, ra, dec;

  // Calculate right ascension (13.3)
  y = sin(DEG_TO_RAD(ecCoord.longitude)) * cos(OBL_ECL_2000_RAD) - tan(DEG_TO_RAD(ecCoord.latitude)) * sin(OBL_ECL_2000_RAD);
  x = cos(DEG_TO_RAD(ecCoord.longitude));

  ra = RAD_TO_HOUR(rad_to_2pi(atan2(y, x)));

  // Calculate declination (13.4)
  sin_dec = sin(DEG_TO_RAD(ecCoord.latitude)) * cos(OBL_ECL_2000_RAD) + cos(DEG_TO_RAD(ecCoord.latitude)) * sin(OBL_ECL_2000_RAD) * sin(DEG_TO_RAD(ecCoord.longitude));

  dec = rad_to_180(asin(sin_dec));

  eqCoord->right_ascension = ra;
  eqCoord->declination = dec;
}

void transform_equatorial_to_local_horizontal_coord(EquatorialCoord_TypeDef eqCoord, GeodeticCoord_TypeDef geoCoord, double jd, LocalHorizontalCoord_TypeDef* lhCoord)
{
  // Initialize variables
  double gmst_deg, local_hour_angle, sin_h, x, y, az, al;
  Time_TypeDef gmst;

  // Calculate Greenwich Mean Sidereal Time (GMST) from Julian Day
  calculate_greenwich_mean_sideral_time_from_jd(jd, &gmst);

  // Convert GMST to decimal degrees
  convert_time_to_decimal_degrees(gmst, &gmst_deg);

  // Calculate Local Hour Angle (LHA) in radians
  local_hour_angle = deg_to_2pi(gmst_deg - geoCoord.longitude - HOUR_TO_DEG(eqCoord.right_ascension));

  // Calculate Azimuth (13.5)
  y = sin(local_hour_angle);
  x = cos(local_hour_angle) * sin(DEG_TO_RAD(geoCoord.latitude)) - tan(DEG_TO_RAD(eqCoord.declination)) * cos(DEG_TO_RAD(geoCoord.latitude));

  az = rad_to_360(atan2(y, x));

  // Calculate Altitude (13.6)
  sin_h = sin(DEG_TO_RAD(geoCoord.latitude)) * sin(DEG_TO_RAD(eqCoord.declination)) + cos(DEG_TO_RAD(geoCoord.latitude)) * cos(DEG_TO_RAD(eqCoord.declination)) * cos(local_hour_angle);

  al = rad_to_180(asin(sin_h));

  lhCoord->azimuth = az;
  lhCoord->altitude = al;
}

void transform_local_horizontal_to_equatorial_coord(LocalHorizontalCoord_TypeDef lhCoord, GeodeticCoord_TypeDef geoCoord, double jd, EquatorialCoord_TypeDef* eqCoord)
{
  // Initialize variables
  double gmst_deg, x, y, local_hour_angle, sin_dec, ra, dec;
  Time_TypeDef gmst;

  // Calculate Greenwich Mean Sidereal Time (GMST) from Julian Day
  calculate_greenwich_mean_sideral_time_from_jd(jd, &gmst);

  // Convert GMST to decimal degrees
  convert_time_to_decimal_degrees(gmst, &gmst_deg);

  // Calculate Right Ascension
  y = sin(DEG_TO_RAD(lhCoord.azimuth));
  x = cos(DEG_TO_RAD(lhCoord.azimuth)) * sin(DEG_TO_RAD(geoCoord.latitude)) + tan(DEG_TO_RAD(lhCoord.altitude)) * cos(DEG_TO_RAD(geoCoord.latitude));

  local_hour_angle = atan2(y, x);
  local_hour_angle = rad_to_360(local_hour_angle);

  ra = deg_to_360(gmst_deg - geoCoord.longitude - local_hour_angle);
  ra = DEG_TO_HOUR(ra);

  // Calculate Declination
  sin_dec = sin(DEG_TO_RAD(geoCoord.latitude)) * sin(DEG_TO_RAD(lhCoord.altitude)) - cos(DEG_TO_RAD(geoCoord.latitude)) * cos(DEG_TO_RAD(lhCoord.altitude)) * cos(DEG_TO_RAD(lhCoord.azimuth));

  dec = rad_to_180(asin(sin_dec));

  eqCoord->right_ascension = ra;
  eqCoord->declination = dec;
}