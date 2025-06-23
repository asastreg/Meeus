
#include "time.h"

#include "utils.h"

#include <math.h>


void get_fraction_day_from_time(Time_TypeDef time, double *fraction_day)
{
  *fraction_day = (time.hour + (time.minute + time.second / 60.0) / 60.0 ) / 24.0;
}

void get_time_from_fraction_day(double fraction_day, Time_TypeDef *time)
{
  double fraction_hour = (fraction_day - (int)fraction_day) * 24.0;
  double fraction_minute = (fraction_hour - (int)fraction_hour) * 60.0;
  double fraction_second = (fraction_minute - (int)fraction_minute) * 60.0;

  time->hour = (unsigned int)fraction_hour;
  time->minute = (unsigned int)fraction_minute;
  time->second = fraction_second;
}

void date_to_jd(Date_TypeDef date, double* jd)
{
  int Y, M, A, B = 0;

  if(date.month > 2)
  {
    Y = date.year;
    M = date.month;
  }
  else
  {
    Y = date.year - 1;
    M = date.month + 12;
  }

  if(date.calendar == CALENDAR_GREGORIAN)
  {
    A = floor(Y / 100);
    B = 2 - A + floor(A / 4);
  }

  double fraction_day;
  get_fraction_day_from_time(date.time, &fraction_day);

  double day = date.day + fraction_day;

  *jd = floor(365.25 * (Y + 4716)) + floor(30.6001 * (M + 1)) + day + B - 1524.5;
}

void jd_to_date(double jd, Date_TypeDef* date)
{
  int A, B, C, D, E, a, m, y;
  double F, Z;

  F = modf(jd + 0.5, &Z);

  if(Z < 2291161)
  {
    A = Z;
  }
  else
  {
    a = floor((Z - 1867216.25) / 36524.25);
    A = Z + 1 + a - floor(a / 4);
  }

  B = A + 1524;
  C = floor((B - 122.1) / 365.25);
  D = floor(365.25 * C);
  E = floor((B - D) / 30.6001);

  // Calculate month number
  if(E < 14)
  {
    m = E - 1;
  }
  else
  {
    m = E - 13;
  }

  // Calculate year number
  if(m > 2)
  {
    y = C - 4716;
  }
  else
  {
    y = C - 4715;
  }

  double day = B - D - floor(30.60001 * E) + F;

  Time_TypeDef time;
  get_time_from_fraction_day(day, &time);

  date->time = time;
  date->day = (unsigned int)day;
  date->month = m;
  date->year = y;
}

void jd_to_mjd(double jd, double* mjd)
{
  *mjd = jd - 2400000.5;
}

void mjd_to_jd(double mjd, double* jd)
{
  *jd = mjd + 2400000.5;
}

void days_interval(Date_TypeDef date1, Date_TypeDef date2, double* interval)
{
  double jd1, jd2;

  date_to_jd(date1, &jd1);
  date_to_jd(date2, &jd2);

  *interval = jd2 - jd1;
}

void day_of_week(Date_TypeDef date, WeekDay_Type *weekDay)
{
  double jd;

  Date_TypeDef date_at_0 = {date.year, date.month, date.day};

  date_to_jd(date_at_0, &jd);

  *weekDay = fmod(jd + 1.5, 7.0);
}

void get_time_from_degrees(double degrees, Time_TypeDef* time)
{
  double fraction_hour = degrees / 15.0;
  double fraction_minute = (fraction_hour - (int)fraction_hour) * 60;
  double fraction_second = (fraction_minute - (int)fraction_minute) * 60;

  time->hour = (unsigned int)fraction_hour;
  time->minute = (unsigned int)fraction_minute;
  time->second = fraction_second;
}

void convert_time_to_decimal_degrees(Time_TypeDef time, double* dec_degrees)
{
  // Initialize variables
  double deg;

  // Calculate degrees from time
  deg = (time.hour + (time.minute + time.second / 60.0) / 60.0) * 15.0;
  deg = deg_to_360(deg);

  *dec_degrees = deg;
}

void convert_degrees_to_decimal_degrees(Degrees_TypeDef degrees, double* dec_degrees)
{
  *dec_degrees = degrees.degree + (degrees.minute + degrees.second / 60.0) / 60.0;
}

void convert_decimal_degrees_to_degrees(double dec_degrees, Degrees_TypeDef* degrees)
{
  // Initialize variables
  double fraction_minute, fraction_second;

  // Calculate degrees, minutes and seconds
  degrees->degree = (int)dec_degrees;
  fraction_minute = fabs(dec_degrees - degrees->degree) * 60.0;
  degrees->minute = (unsigned int)fraction_minute;
  fraction_second = (fraction_minute - degrees->minute) * 60.0;
  degrees->second = fraction_second;
}

void calculate_greenwich_mean_sideral_time_from_jd(double jd, Time_TypeDef* gmst)
{
  // Initialize variables
  double T, gmst_deg;

  // Calculate the Julian centuries since J2000.0
  calculate_julian_centuries_from_jd(jd, &T);

  // Calculate GMST in degrees
  gmst_deg = 280.46061837 + 360.98564736629 * (jd - 2451545.0) + 0.000387933 * T * T - (T * T * T) / 38710000.0;
  gmst_deg = deg_to_360(gmst_deg);

  // Convert GMST from degrees to time
  get_time_from_degrees(gmst_deg, gmst);
}

void calculate_greenwich_mean_sideral_time_from_date(Date_TypeDef date, Time_TypeDef* gmst)
{
  // Initialize variables
  double jd;

  // Convert the date to Julian day
  date_to_jd(date, &jd);

  // Calculate GMST from Julian day
  calculate_greenwich_mean_sideral_time_from_jd(jd, gmst);
}

void calculate_julian_centuries_from_jd(double jd, double* T)
{
  *T = (jd - 2451545.0) / 36525.0;
}