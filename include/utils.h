
#ifndef UTILS_H
#define UTILS_H

#include <math.h>


#define RAD_TO_DEG(rad)     ((rad) * 57.29577951)
#define RAD_TO_HOUR(rad)    ((rad) * 3.8197186342)
#define DEG_TO_RAD(deg)     ((deg) * 0.01745329252)
#define DEG_TO_HOUR(deg)    ((deg) * 0.06666666667)
#define HOUR_TO_RAD(hour)   ((hour) * 0.2617993878)
#define HOUR_TO_DEG(hour)   ((hour) * 15.0)

/**
 * @brief Normalize angle to [0, 360) degrees
 *
 * @param deg Input angle in degrees
 * @return double Output angle in degrees
 */
double deg_to_360(double deg);

/**
 * @brief Normalize angle to [-180, 180) degrees
 *
 * @param deg Input angle in degrees
 * @return double Output angle in degrees
 */
double deg_to_180(double deg);

/**
 * @brief Normalize angle to [0, 2π) radians
 *
 * @param deg Input angle in degrees
 * @return double Output angle in radians
 */
double deg_to_2pi(double deg);

/**
 * @brief Normalize angle to [-π, π) radians
 *
 * @param deg Input angle in degrees
 * @return double Output angle in radians
 */
double deg_to_pi(double deg);

/**
 * @brief Normalize radian angle to [0, 360) degrees
 *
 * @param rad Input angle in radians
 * @return double Output angle in degrees
 */
double rad_to_360(double rad);

/**
 * @brief Normalize radian angle to [-180, 180) degrees
 *
 * @param rad Input angle in radians
 * @return double Output angle in degrees
 */
double rad_to_180(double rad);

/**
 * @brief Normalize angle to [0, 2π) radians
 *
 * @param rad Input angle in radians
 * @return double Output angle in radians
 */
double rad_to_2pi(double rad);

/**
 * @brief Normalize angle to [-π, π) radians
 *
 * @param rad Input angle in radians
 * @return double Output angle in radians
 */
double rad_to_pi(double rad);

#endif