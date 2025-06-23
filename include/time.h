
#ifndef TIME_H
#define TIME_H

#include "data.h"


/**
 * @brief Get the fraction day from Time
 *
 * @param time Time object
 * @param fraction_day Fraction of day
 */
void get_fraction_day_from_time(Time_TypeDef time, double* fraction_day);

/**
 * @brief Get the Time from a fraction day
 *
 * @param fraction_day
 * @param time Time
 */
void get_time_from_fraction_day(double fraction_day, Time_TypeDef* time);

/**
 * @brief Convert calendar date into julian day
 *
 * @param date Calendar date
 * @param jd Julian day
 */
void date_to_jd(Date_TypeDef date, double* jd);

/**
 * @brief Convert julian day to calendar date
 *
 * @param jd Julian day
 * @param date Calendar date
 */
void jd_to_date(double jd, Date_TypeDef* date);

/**
 * @brief Convert julian day into modified julian day
 *
 * @param jd Julian day
 * @param mjd Modified julian day
 */
void jd_to_mjd(double jd, double* mjd);

/**
 * @brief Convert modified julian day into julian day
 *
 * @param mjd Modified julian day
 * @param jd Julian day
 */
void mjd_to_jd(double mjd, double* jd);

/**
 * @brief Calculate number of day bewteen two dates
 *
 * @param date1 Date one
 * @param date2 Date two
 * @param interval Interval days
 */
void days_interval(Date_TypeDef date1, Date_TypeDef date2, double* interval);

/**
 * @brief Calculate the day of the week corresponding to a given date
 *
 * @param date
 * @param WeekDay_Type
 */
void day_of_week(Date_TypeDef date, WeekDay_Type* weekDay);


void get_time_from_degrees(double degrees, Time_TypeDef* time);

/**
 * @brief Get the degrees [0, 360) from a Time object
 *
 * @param time Input Time object
 * @param degrees Output degrees
 */
void convert_time_to_decimal_degrees(Time_TypeDef time, double* degrees);


void convert_degrees_to_decimal_degrees(Degrees_TypeDef degrees, double* dec_degrees);


void convert_decimal_degrees_to_degrees(double dec_degrees, Degrees_TypeDef* degrees);


void calculate_greenwich_mean_sideral_time_from_jd(double jd, Time_TypeDef* gmst);


void get_greenwich_mean_sideral_time_from_date(Date_TypeDef date, Time_TypeDef* gmst);

/**
 * @brief Calculate the Julian centuries from a given Julian day
 *
 * @param jd Julian day
 * @param T Julian centuries since J2000.0
 */
void calculate_julian_centuries_from_jd(double jd, double* T);

#endif