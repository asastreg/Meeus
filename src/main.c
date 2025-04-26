
#include <stdio.h>

#include "coordinates.h"
#include "time.h"

int main()
{
  Date_TypeDef date = {1987, 4, 10, 19, 21, 0};
  GeodeticCoord_TypeDef geoCoord = {-77.06703, 38.92087};
  EquatorialCoord_TypeDef venusEq = {23.1546225, -6.71989166};
  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(venusEq, geoCoord, date, &lhCoord);

  printf("%f %f\n", lhCoord.azimuth, lhCoord.altitude);

  return 0;
}