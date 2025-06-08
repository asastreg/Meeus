#include "coordinates.h"
#include "time.h"

#include <stdio.h>

int main(void)
{
  EquatorialCoord_TypeDef eqCoord = {7.755262, 28.026183};
  EclipticalCoord_TypeDef ecCoord;

  transform_equatorial_to_ecliptical_coord(eqCoord, &ecCoord);
  printf("Longitude: %f, Latitude: %f\n", ecCoord.longitude, ecCoord.latitude);

  return 0;
}
