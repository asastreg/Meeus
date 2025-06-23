/**
 * @file test_coordinates.c
 * @brief Unit tests for the coordinates.h module.
 *
 * This file contains unit tests to verify the correctness and robustness
 * of the functions and data structures defined in coordinates.h.
 *
 * The tests cover:
 * - Initialization and manipulation of coordinate structures.
 * - Validation of coordinate operations (e.g., addition, comparison).
 * - Edge cases and error handling.
 *
 * Usage:
 * Compile with the coordinates.h implementation and run the resulting binary.
 *
 * @author [Your Name]
 * @date [Date]
 *
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-06-08
 *
 * @copyright Copyright (c) 2025
 *
 * @file coordinates_test.c
 **/


#include "unity.h"

#include "coordinates.h"
#include "time.h"


void setUp(void) {
  // Set up code here, if needed
}
void tearDown(void) {
  // Tear down code here, if needed
}

void test_transform_equatorial_to_ecliptical_coord_001(void)
{
  EquatorialCoord_TypeDef eqCoord = {7.755262, 28.026183};
  EclipticalCoord_TypeDef ecCoord;

  transform_equatorial_to_ecliptical_coord(eqCoord, &ecCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 113.215630, ecCoord.longitude);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 6.684170, ecCoord.latitude);
}

void test_transform_ecliptical_to_equatorial_coord_001(void)
{
  EclipticalCoord_TypeDef ecCoord = {113.215630, 6.684170};
  EquatorialCoord_TypeDef eqCoord;

  transform_ecliptical_to_equatorial_coord(ecCoord, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 7.755262, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 28.026183, eqCoord.declination);
}


void test_transform_equatorial_to_local_horizontal_coord_001(void)
{
  EquatorialCoord_TypeDef eqCoord = {10.139769, 11.965861};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2451544.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 283.974695, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 33.717048, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_002(void)
{
  EquatorialCoord_TypeDef eqCoord = {2.513563, 89.259694};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 180.709556, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 39.950998, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_003(void)
{
  EquatorialCoord_TypeDef eqCoord = {19.846975, 8.870583};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 308.322595, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 47.105468, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_004(void)
{
  EquatorialCoord_TypeDef eqCoord = {6.398602, -52.696111};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 27.787389, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, -75.652227, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_005(void)
{
  EquatorialCoord_TypeDef eqCoord = {5.919166, 7.407083};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 174.928790, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, -42.009679, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_006(void)
{
  EquatorialCoord_TypeDef eqCoord = {14.450361, -83.672361};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 5.838636, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, -36.089099, lhCoord.altitude);
}

void test_transform_equatorial_to_local_horizontal_coord_007(void)
{
  EquatorialCoord_TypeDef eqCoord = {20.690063, 45.282194}; // Invalid coordinates
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2451544.5; // Julian day for 2000-01-01

  LocalHorizontalCoord_TypeDef lhCoord;

  transform_equatorial_to_local_horizontal_coord(eqCoord, geoCoord, jd, &lhCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 156.920331, lhCoord.azimuth);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 0.941923, lhCoord.altitude);
}


void test_transform_local_horizontal_coord_to_equatorial_001(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {114.189700, -8.923499};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 10.139241, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 11.968222, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_002(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {180.709556, 39.950998};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 2.513563, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 89.259694, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_003(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {308.322595, 47.105468};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 19.846975, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 8.870583, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_004(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {27.787389, -75.652227};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 6.398602, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, -52.696111, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_005(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {174.928790, -42.009679};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 5.919166, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 7.407083, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_006(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {5.838636, -36.089099};
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2460846.5; // Julian day for 2025-06-20

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 14.450361, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, -83.672361, eqCoord.declination);
}

void test_transform_local_horizontal_coord_to_equatorial_007(void)
{
  LocalHorizontalCoord_TypeDef lhCoord = {156.920331, 0.941923}; // Invalid coordinates
  GeodeticCoord_TypeDef geoCoord = {3.469730, 40.455350};
  double jd = 2451544.5; // Julian day for 2000-01-01

  EquatorialCoord_TypeDef eqCoord;

  transform_local_horizontal_to_equatorial_coord(lhCoord, geoCoord, jd, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 20.690063, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 45.282194, eqCoord.declination);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_transform_equatorial_to_ecliptical_coord_001);
  RUN_TEST(test_transform_ecliptical_to_equatorial_coord_001);

  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_001);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_002);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_003);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_004);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_005);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_006);
  RUN_TEST(test_transform_equatorial_to_local_horizontal_coord_007);

  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_001);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_002);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_003);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_004);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_005);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_006);
  RUN_TEST(test_transform_local_horizontal_coord_to_equatorial_007);

  return UNITY_END();
}