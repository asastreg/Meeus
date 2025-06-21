
#include "coordinates.h"

#include "time.h"
#include "utils.h"

#include <math.h>

void transform_equatorial_to_ecliptical_coord(EquatorialCoord_TypeDef eqCoord, EclipticalCoord_TypeDef* ecCoord)
{
  double lon, lat;

  // Calculate ecliptical longitude (13.1)
  double y = sin(HOUR_TO_RAD(eqCoord.right_ascension)) * cos(OBL_ECL_2000_RAD) + tan(DEG_TO_RAD(eqCoord.declination)) * sin(OBL_ECL_2000_RAD);
  double x = cos(HOUR_TO_RAD(eqCoord.right_ascension));

  lon = rad_to_360(atan2(y, x));

  // Calculate ecliptical latitude (13.2)
  double sin_B = sin(DEG_TO_RAD(eqCoord.declination)) * cos(OBL_ECL_2000_RAD) - cos(DEG_TO_RAD(eqCoord.declination)) * sin(OBL_ECL_2000_RAD) * sin(HOUR_TO_RAD(eqCoord.right_ascension));

  lat = rad_to_180(asin(sin_B));

  ecCoord->longitude = lon;
  ecCoord->latitude = lat;
}

void transform_ecliptical_to_equatorial_coord(EclipticalCoord_TypeDef ecCoord, EquatorialCoord_TypeDef* eqCoord)
{
  double ra, dec;

  // Calculate right ascension (13.3)
  double y = sin(DEG_TO_RAD(ecCoord.longitude)) * cos(OBL_ECL_2000_RAD) - tan(DEG_TO_RAD(ecCoord.latitude)) * sin(OBL_ECL_2000_RAD);
  double x = cos(DEG_TO_RAD(ecCoord.longitude));

  ra = RAD_TO_HOUR(rad_to_2pi(atan2(y, x)));

  // Calculate declination (13.4)
  double sin_dec = sin(DEG_TO_RAD(ecCoord.latitude)) * cos(OBL_ECL_2000_RAD) + cos(DEG_TO_RAD(ecCoord.latitude)) * sin(OBL_ECL_2000_RAD) * sin(DEG_TO_RAD(ecCoord.longitude));

  dec = rad_to_180(asin(sin_dec));

  eqCoord->right_ascension = ra;
  eqCoord->declination = dec;
}

void transform_equatorial_to_local_horizontal_coord(EquatorialCoord_TypeDef eqCoord, GeodeticCoord_TypeDef geoCoord, double jd, LocalHorizontalCoord_TypeDef* lhCoord)
{
  double az, al;

  // Calculate Greenwich Mean Sidereal Time (GMST) from Julian Day
  Time_TypeDef gmst;
  get_greenwich_mean_sideral_time_from_jd(jd, &gmst);

  // Convert GMST to decimal degrees
  double gmst_deg;
  convert_time_to_decimal_degrees(gmst, &gmst_deg);

  // Calculate Local Hour Angle (LHA) in radians
  double local_hour_angle = deg_to_2pi(gmst_deg - geoCoord.longitude - HOUR_TO_DEG(eqCoord.right_ascension));

  // Calculate Azimuth (13.5)
  double y = sin(local_hour_angle);
  double x = cos(local_hour_angle) * sin(DEG_TO_RAD(geoCoord.latitude)) - tan(DEG_TO_RAD(eqCoord.declination)) * cos(DEG_TO_RAD(geoCoord.latitude));

  az = rad_to_360(atan2(y, x));

  // Calculate Altitude (13.6)
  double sin_h = sin(DEG_TO_RAD(geoCoord.latitude)) * sin(DEG_TO_RAD(eqCoord.declination)) + cos(DEG_TO_RAD(geoCoord.latitude)) * cos(DEG_TO_RAD(eqCoord.declination)) * cos(local_hour_angle);

  al = rad_to_180(asin(sin_h));

  lhCoord->azimuth = az;
  lhCoord->altitude = al;
}