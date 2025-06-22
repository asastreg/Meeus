
#include "unity.h"
#include "time.h"


void setUp(void)
{
  // Set up code here, if needed
}
void tearDown(void)
{
  // Tear down code here, if needed
}

void test_date_to_jd_001(void)
{
  Date_TypeDef date = {2000, 1, 1, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2451545.0, jd);
}

void test_date_to_jd_002(void)
{
  Date_TypeDef date = {1999, 1, 1, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2451179.5, jd);
}

void test_date_to_jd_003(void)
{
  Date_TypeDef date = {1987, 1, 27, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2446822.5, jd);
}

void test_date_to_jd_004(void)
{
  Date_TypeDef date = {1987, 6, 19, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2446966.0, jd);
}

void test_date_to_jd_005(void)
{
  Date_TypeDef date = {1988, 1, 27, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2447187.5, jd);
}

void test_date_to_jd_006(void)
{
  Date_TypeDef date = {1988, 6, 19, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2447332.0, jd);
}

void test_date_to_jd_007(void)
{
  Date_TypeDef date = {1900, 1, 1, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2415020.5, jd);
}

void test_date_to_jd_008(void)
{
  Date_TypeDef date = {1600, 1, 1, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2305447.5, jd);
}

void test_date_to_jd_009(void)
{
  Date_TypeDef date = {1600, 12, 31, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2305812.5, jd);
}

void test_date_to_jd_010(void)
{
  Date_TypeDef date = {837, 4, 10, {7, 12, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2026871.8, jd);
}

void test_date_to_jd_011(void)
{
  Date_TypeDef date = {-123, 12, 31, {0, 0, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1676496.5, jd);
}

void test_date_to_jd_012(void)
{
  Date_TypeDef date = {-122, 1, 1, {0, 0, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1676497.5, jd);
}

void test_date_to_jd_013(void)
{
  Date_TypeDef date = {-1000, 7, 12, {12, 0, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1356001.0, jd);
}

void test_date_to_jd_014(void)
{
  Date_TypeDef date = {-1000, 2, 29, {0, 0, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1355866.5, jd);
}

void test_date_to_jd_015(void)
{
  Date_TypeDef date = {-1001, 8, 17, {21, 36, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1355671.4, jd);
}

void test_date_to_jd_016(void)
{
  Date_TypeDef date = {-4712, 1, 1, {12, 0, 0.0}, CALENDAR_JULIAN};
  double jd;

  date_to_jd(date, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, jd);
}

void test_jd_to_date_001(void)
{
  double jd = 2451545.0;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(2000, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(12, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}


void test_jd_to_date_002(void)
{
  double jd = 2451179.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1999, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_003(void)
{
  double jd = 2446822.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1987, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(27, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_004(void)
{
  double jd = 2446966.0;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1987, date.year);
  TEST_ASSERT_EQUAL(6, date.month);
  TEST_ASSERT_EQUAL(19, date.day);
  TEST_ASSERT_EQUAL(12, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_005(void)
{
  double jd = 2447187.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1988, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(27, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_006(void)
{
  double jd = 2447332.0;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1988, date.year);
  TEST_ASSERT_EQUAL(6, date.month);
  TEST_ASSERT_EQUAL(19, date.day);
  TEST_ASSERT_EQUAL(12, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_007(void)
{
  double jd = 2415020.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1900, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_008(void)
{
  double jd = 2305447.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1600, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_009(void)
{
  double jd = 2305812.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(1600, date.year);
  TEST_ASSERT_EQUAL(12, date.month);
  TEST_ASSERT_EQUAL(31, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_010(void)
{
  double jd = 2026871.8;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(837, date.year);
  TEST_ASSERT_EQUAL(4, date.month);
  TEST_ASSERT_EQUAL(10, date.day);
  TEST_ASSERT_EQUAL(7, date.time.hour);
  TEST_ASSERT_EQUAL(12, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_011(void)
{
  double jd = 1676496.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-123, date.year);
  TEST_ASSERT_EQUAL(12, date.month);
  TEST_ASSERT_EQUAL(31, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_012(void)
{
  double jd = 1676497.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-122, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_013(void)
{
  double jd = 1356001.0;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-1000, date.year);
  TEST_ASSERT_EQUAL(7, date.month);
  TEST_ASSERT_EQUAL(12, date.day);
  TEST_ASSERT_EQUAL(12, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_014(void)
{
  double jd = 1355866.5;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-1000, date.year);
  TEST_ASSERT_EQUAL(2, date.month);
  TEST_ASSERT_EQUAL(29, date.day);
  TEST_ASSERT_EQUAL(0, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_015(void)
{
  double jd = 1355671.400000001;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-1001, date.year);
  TEST_ASSERT_EQUAL(8, date.month);
  TEST_ASSERT_EQUAL(17, date.day);
  TEST_ASSERT_EQUAL(21, date.time.hour);
  TEST_ASSERT_EQUAL(36, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_jd_to_date_016(void)
{
  double jd = 0.0;
  Date_TypeDef date;

  jd_to_date(jd, &date);

  TEST_ASSERT_EQUAL(-4712, date.year);
  TEST_ASSERT_EQUAL(1, date.month);
  TEST_ASSERT_EQUAL(1, date.day);
  TEST_ASSERT_EQUAL(12, date.time.hour);
  TEST_ASSERT_EQUAL(0, date.time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, date.time.second);
}

void test_get_time_from_fraction_day_001(void)
{
  Time_TypeDef time;
  double fraction_day = 0.0;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(0, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_002(void)
{
  Time_TypeDef time;
  double fraction_day = 0.25;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(6, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_003(void)
{
  Time_TypeDef time;
  double fraction_day = 0.5;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(12, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_004(void)
{
  Time_TypeDef time;
  double fraction_day = 0.75;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(18, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_005(void)
{
  Time_TypeDef time;
  double fraction_day = 1.0;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(0, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_006(void)
{
  Time_TypeDef time;
  double fraction_day = 0.041666666666666664; // 1 hour

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(1, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_007(void)
{
  Time_TypeDef time;
  double fraction_day = 0.020833333333333332; // 30 minutes

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(0, time.hour);
  TEST_ASSERT_EQUAL(30, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_008(void)
{
  Time_TypeDef time;
  double fraction_day = 0.0006944444444444445; // 1 minute

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(0, time.hour);
  TEST_ASSERT_EQUAL(1, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_time_from_fraction_day_009(void)
{
  Time_TypeDef time;
  double fraction_day = 0.000011574074074074073; // 1 second

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(0, time.hour);
  TEST_ASSERT_EQUAL(0, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, time.second);
}

void test_get_time_from_fraction_day_010(void)
{
  Time_TypeDef time;
  double fraction_day = 0.9;

  get_time_from_fraction_day(fraction_day, &time);

  TEST_ASSERT_EQUAL(21, time.hour);
  TEST_ASSERT_EQUAL(36, time.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, time.second);
}

void test_get_fraction_day_from_time_001(void)
{
  Time_TypeDef time = {0, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, fraction_day);
}

void test_get_fraction_day_from_time_002(void)
{
  Time_TypeDef time = {6, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.25, fraction_day);
}

void test_get_fraction_day_from_time_003(void)
{
  Time_TypeDef time = {12, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.5, fraction_day);
}

void test_get_fraction_day_from_time_004(void)
{
  Time_TypeDef time = {18, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.75, fraction_day);
}

void test_get_fraction_day_from_time_005(void)
{
  Time_TypeDef time = {24, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, fraction_day);
}

void test_get_fraction_day_from_time_006(void)
{
  Time_TypeDef time = {1, 0, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.041666666666666664, fraction_day);
}

void test_get_fraction_day_from_time_007(void)
{
  Time_TypeDef time = {0, 30, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.020833333333333332, fraction_day);
}

void test_get_fraction_day_from_time_008(void)
{
  Time_TypeDef time = {0, 1, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0006944444444444445, fraction_day);
}

void test_get_fraction_day_from_time_009(void)
{
  Time_TypeDef time = {0, 0, 1.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.000011574074074074073, fraction_day);
}

void test_get_fraction_day_from_time_010(void)
{
  Time_TypeDef time = {21, 36, 0.0};
  double fraction_day;

  get_fraction_day_from_time(time, &fraction_day);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.9, fraction_day);
}

void test_jd_to_mjd_001(void)
{
  double jd = 2451545.0;
  double mjd;

  jd_to_mjd(jd, &mjd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 51544.5, mjd);
}

void test_jd_to_mjd_002(void)
{
  double jd = 2400000.5;
  double mjd;

  jd_to_mjd(jd, &mjd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, mjd);
}

void test_mjd_to_jd_001(void)
{
  double mjd = 51544.5;
  double jd;

  mjd_to_jd(mjd, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2451545.0, jd);
}

void test_mjd_to_jd_002(void)
{
  double mjd = 0.0;
  double jd;

  mjd_to_jd(mjd, &jd);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 2400000.5, jd);
}

void test_days_interval_001(void)
{
  Date_TypeDef date1 = {2000, 1, 1, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  Date_TypeDef date2 = {2000, 1, 2, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  double interval;

  days_interval(date1, date2, &interval);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 1.0, interval);
}

void test_days_interval_002(void)
{
  Date_TypeDef date1 = {2000, 1, 1, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  Date_TypeDef date2 = {2000, 1, 1, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  double interval;

  days_interval(date1, date2, &interval);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 0.0, interval);
}

void test_days_interval_003(void)
{
  Date_TypeDef date1 = {1910, 4, 20, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  Date_TypeDef date2 = {1986, 2, 9, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  double interval;

  days_interval(date1, date2, &interval);

  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 27689.0, interval);
}

void test_day_of_week_001(void)
{
  Date_TypeDef date = {1954, 6, 30, {0, 0, 0.0}, CALENDAR_GREGORIAN};
  WeekDay_Type weekDay;

  day_of_week(date, &weekDay);

  TEST_ASSERT_EQUAL(WEDNESDAY, weekDay);
}

void test_day_of_week_002(void)
{
  Date_TypeDef date = {1998, 5, 7, {12, 0, 0.0}, CALENDAR_GREGORIAN};
  WeekDay_Type weekDay;

  day_of_week(date, &weekDay);

  TEST_ASSERT_EQUAL(THURSDAY, weekDay);
}

void test_day_of_week_003(void)
{
  Date_TypeDef date = {2000, 3, 3, {3, 0, 0.0}, CALENDAR_GREGORIAN};
  WeekDay_Type weekDay;

  day_of_week(date, &weekDay);

  TEST_ASSERT_EQUAL(FRADAY, weekDay);
}

void test_day_of_week_004(void)
{
  Date_TypeDef date = {1582, 10, 4, {18, 0, 0.0}, CALENDAR_JULIAN};
  WeekDay_Type weekDay;

  day_of_week(date, &weekDay);

  TEST_ASSERT_EQUAL(THURSDAY, weekDay);
}

void test_day_of_week_005(void)
{
  Date_TypeDef date = {1582, 10, 15, {18, 0, 0.0}, CALENDAR_GREGORIAN};
  WeekDay_Type weekDay;

  day_of_week(date, &weekDay);

  TEST_ASSERT_EQUAL(FRADAY, weekDay);
}



void test_get_greenwich_mean_sideral_time_from_date_001(void)
{
  Date_TypeDef date = {1987, 4, 10, {19, 21, 0.0}, CALENDAR_GREGORIAN};
  Time_TypeDef gmst;

  get_greenwich_mean_sideral_time_from_date(date, &gmst);

  TEST_ASSERT_EQUAL(8, gmst.hour);
  TEST_ASSERT_EQUAL(34, gmst.minute);
  TEST_ASSERT_DOUBLE_WITHIN(0.0001, 57.0896, gmst.second);
}


int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_date_to_jd_001);
  RUN_TEST(test_date_to_jd_002);
  RUN_TEST(test_date_to_jd_003);
  RUN_TEST(test_date_to_jd_004);
  RUN_TEST(test_date_to_jd_005);
  RUN_TEST(test_date_to_jd_006);
  RUN_TEST(test_date_to_jd_007);
  RUN_TEST(test_date_to_jd_008);
  RUN_TEST(test_date_to_jd_009);
  RUN_TEST(test_date_to_jd_010);
  RUN_TEST(test_date_to_jd_011);
  RUN_TEST(test_date_to_jd_012);
  RUN_TEST(test_date_to_jd_013);
  RUN_TEST(test_date_to_jd_014);
  RUN_TEST(test_date_to_jd_015);
  RUN_TEST(test_date_to_jd_016);

  RUN_TEST(test_jd_to_date_001);
  RUN_TEST(test_jd_to_date_002);
  RUN_TEST(test_jd_to_date_003);
  RUN_TEST(test_jd_to_date_004);
  RUN_TEST(test_jd_to_date_005);
  RUN_TEST(test_jd_to_date_006);
  RUN_TEST(test_jd_to_date_007);
  RUN_TEST(test_jd_to_date_008);
  RUN_TEST(test_jd_to_date_009);
  RUN_TEST(test_jd_to_date_010);
  RUN_TEST(test_jd_to_date_011);
  RUN_TEST(test_jd_to_date_012);
  RUN_TEST(test_jd_to_date_013);
  RUN_TEST(test_jd_to_date_014);
  RUN_TEST(test_jd_to_date_015);
  RUN_TEST(test_jd_to_date_016);

  RUN_TEST(test_get_time_from_fraction_day_001);
  RUN_TEST(test_get_time_from_fraction_day_002);
  RUN_TEST(test_get_time_from_fraction_day_003);
  RUN_TEST(test_get_time_from_fraction_day_004);
  RUN_TEST(test_get_time_from_fraction_day_005);
  RUN_TEST(test_get_time_from_fraction_day_006);
  RUN_TEST(test_get_time_from_fraction_day_007);
  RUN_TEST(test_get_time_from_fraction_day_008);
  RUN_TEST(test_get_time_from_fraction_day_009);
  RUN_TEST(test_get_time_from_fraction_day_010);

  RUN_TEST(test_get_fraction_day_from_time_001);
  RUN_TEST(test_get_fraction_day_from_time_002);
  RUN_TEST(test_get_fraction_day_from_time_003);
  RUN_TEST(test_get_fraction_day_from_time_004);
  RUN_TEST(test_get_fraction_day_from_time_005);
  RUN_TEST(test_get_fraction_day_from_time_006);
  RUN_TEST(test_get_fraction_day_from_time_007);
  RUN_TEST(test_get_fraction_day_from_time_008);
  RUN_TEST(test_get_fraction_day_from_time_009);
  RUN_TEST(test_get_fraction_day_from_time_010);

  RUN_TEST(test_jd_to_mjd_001);
  RUN_TEST(test_jd_to_mjd_002);

  RUN_TEST(test_mjd_to_jd_001);
  RUN_TEST(test_mjd_to_jd_002);

  RUN_TEST(test_days_interval_001);
  RUN_TEST(test_days_interval_002);
  RUN_TEST(test_days_interval_003);

  RUN_TEST(test_day_of_week_001);
  RUN_TEST(test_day_of_week_002);
  RUN_TEST(test_day_of_week_003);
  // RUN_TEST(test_day_of_week_004);
  RUN_TEST(test_day_of_week_005);

  RUN_TEST(test_get_greenwich_mean_sideral_time_from_date_001);

  return UNITY_END();
}