
#ifndef COORDINATES_H
#define COORDINATES_H

#include "data.h"


void transform_equatorial_to_eclitical_coord(EquatorialCoord_TypeDef eqCoord, EclipticalCoord_TypeDef* ecCoord);


void transform_eclitical_to_equatorial_coord(EclipticalCoord_TypeDef ecCoord, EquatorialCoord_TypeDef* eqCoord);


void transform_equatorial_to_local_horizontal_coord(EquatorialCoord_TypeDef eqCoord, GeodeticCoord_TypeDef geoCoord, Date_TypeDef date, LocalHorizontalCoord_TypeDef* lhCoord);


#endif