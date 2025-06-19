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


void setUp(void) {
  // Set up code here, if needed
}
void tearDown(void) {
  // Tear down code here, if needed
}

void test_transform_equatorial_to_ecliptical_coord(void)
{
  EquatorialCoord_TypeDef eqCoord = {7.755262, 28.026183};
  EclipticalCoord_TypeDef ecCoord;

  transform_equatorial_to_ecliptical_coord(eqCoord, &ecCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 113.215630, ecCoord.longitude);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 6.684170, ecCoord.latitude);
}

void test_transform_ecliptical_to_equatorial_coord(void)
{
  EclipticalCoord_TypeDef ecCoord = {113.215630, 6.684170};
  EquatorialCoord_TypeDef eqCoord;

  transform_ecliptical_to_equatorial_coord(ecCoord, &eqCoord);

  TEST_ASSERT_FLOAT_WITHIN(0.0001, 7.755262, eqCoord.right_ascension);
  TEST_ASSERT_FLOAT_WITHIN(0.0001, 28.026183, eqCoord.declination);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_transform_equatorial_to_ecliptical_coord);
  RUN_TEST(test_transform_ecliptical_to_equatorial_coord);

  return UNITY_END();
}