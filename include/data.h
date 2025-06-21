
#ifndef DATA_H
#define DATA_H

#define OBL_ECL_2000_DEG 23.4392911
#define OBL_ECL_2000_RAD 0.4090928042

typedef enum
{
  CALENDAR_GREGORIAN,
  CALENDAR_JULIAN
} Calendar_Type;


typedef enum
{
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRADAY,
  SATURDAY
} WeekDay_Type;


typedef struct
{
  unsigned int hour;
  unsigned int minute;
  double second;
} Time_TypeDef;


typedef struct
{
  int year;
  unsigned int month;
  unsigned int day;
  Time_TypeDef time;
  Calendar_Type calendar;
} Date_TypeDef;


typedef struct
{
  int degree;
  unsigned int minute;
  double second;
} Degrees_TypeDef;


typedef struct
{
  double right_ascension; ///< Measured from north to east (hour)
  double declination; ///< Positive in north of celestial equator, negative if south (deg)
} EquatorialCoord_TypeDef;


typedef struct
{
  double longitude; ///< Measured from the vernal equinox along the ecliptic (deg)
  double latitude;  ///< Positive if north of the ecliptic, negative if south (deg)
} EclipticalCoord_TypeDef;


typedef struct
{
  double azimuth; ///< Measured from south to west (deg)
  double altitude; ///< Positive above the horizon, negative below (deg)
} LocalHorizontalCoord_TypeDef;


typedef struct
{
  double longitude; ///< Measured from the main meridian, positive west, negative east (deg)
  double latitude;  ///< Positive if north of equator, negative if south (deg)
} GeodeticCoord_TypeDef;

#endif