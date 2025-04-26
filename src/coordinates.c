
#include "coordinates.h"

#include "time.h"

#include <math.h>

#include <stdio.h>

void transform_equatorial_to_eclitical_coord(EquatorialCoord_TypeDef eqCoord, EclipticalCoord_TypeDef* ecCoord)
{
  double x = cos(eqCoord.right_ascension * 15.0 * deg2rad);
  double y = sin(eqCoord.right_ascension * 15.0 * deg2rad) * cos(obl_ecliptic_2000 * deg2rad) + tan(eqCoord.declination * deg2rad) * sin(obl_ecliptic_2000 * deg2rad);

  double sin_B = sin(eqCoord.declination * deg2rad) * cos(obl_ecliptic_2000 * deg2rad) - cos(eqCoord.declination * deg2rad) * sin(obl_ecliptic_2000 * deg2rad) * sin(eqCoord.right_ascension * 15.0 * deg2rad);

  ecCoord->longitude = atan2(y, x) * rad2deg;
  ecCoord->latitude = asin(sin_B) * rad2deg;
}

void transform_eclitical_to_equatorial_coord(EclipticalCoord_TypeDef ecCoord, EquatorialCoord_TypeDef* eqCoord)
{
  double x = cos(ecCoord.longitude * deg2rad);
  double y = sin(ecCoord.longitude * deg2rad) * cos(obl_ecliptic_2000 * deg2rad) - tan(ecCoord.latitude * deg2rad) * sin(obl_ecliptic_2000 * deg2rad);

  double sin_dec = sin(ecCoord.latitude * deg2rad) * cos(obl_ecliptic_2000 * deg2rad) + cos(ecCoord.latitude * deg2rad) * sin(obl_ecliptic_2000 * deg2rad) * sin(ecCoord.longitude * deg2rad);

  eqCoord->right_ascension = atan2(y, x) * rad2deg / 15.0;
  eqCoord->declination = asin(sin_dec) * rad2deg;
}

void transform_equatorial_to_local_horizontal_coord(EquatorialCoord_TypeDef eqCoord, GeodeticCoord_TypeDef geoCoord, Date_TypeDef date, LocalHorizontalCoord_TypeDef* lhCoord)
{
  Time_TypeDef gmst;
  get_greenwich_mean_sideral_time(date, &gmst);

  double gmst_deg;
  get_decimal_degrees_from_time(gmst, &gmst_deg);

  double local_hour_angle = fmod(fmod(gmst_deg + geoCoord.longitude - eqCoord.right_ascension * 15.0, 360) + 360, 360);

  double x = cos(local_hour_angle * deg2rad) * sin(geoCoord.latitude * deg2rad) - tan(eqCoord.declination * deg2rad) * cos(geoCoord.latitude * deg2rad);
  double y = sin(local_hour_angle * deg2rad);

  double sin_h = sin(geoCoord.latitude * deg2rad) * sin(eqCoord.declination * deg2rad) + cos(geoCoord.latitude * deg2rad) * cos(eqCoord.declination * deg2rad) * cos(local_hour_angle * deg2rad);

  lhCoord->azimuth = atan2(y, x) * rad2deg;
  lhCoord->altitude = asin(sin_h) * rad2deg;
}