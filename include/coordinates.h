
#ifndef COORDINATES_H
#define COORDINATES_H

#include "data.h"


/**
 * @brief Transform equatorial coordinates to ecliptical coordinates
 *
 * @param eqCoord Input equatorial coordinates
 * @param ecCoord Output ecliptical coordinates
 */
void transform_equatorial_to_ecliptical_coord(EquatorialCoord_TypeDef eqCoord, EclipticalCoord_TypeDef* ecCoord);

/**
 * @brief Transform ecliptical coordinates to equatorial coordinates
 *
 * @param ecCoord Input ecliptical coordinates
 * @param eqCoord Output equatorial coordinates
 */
void transform_ecliptical_to_equatorial_coord(EclipticalCoord_TypeDef ecCoord, EquatorialCoord_TypeDef* eqCoord);

/**
 * @brief Transform equatorial coordinates to local horizontal coordinates
 *
 * @param eqCoord Input equatorial coordinates
 * @param geoCoord Geodetic coordinates of the observer
 * @param jd Julian day of the observation
 * @param lhCoord Output local horizontal coordinates
 */
void transform_equatorial_to_local_horizontal_coord(EquatorialCoord_TypeDef eqCoord, GeodeticCoord_TypeDef geoCoord, double jd, LocalHorizontalCoord_TypeDef* lhCoord);


#endif