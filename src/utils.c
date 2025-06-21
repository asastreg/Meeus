
#include "utils.h"

double deg_to_360(double deg)
{
  return fmod(fmod(deg, 360.0) + 360.0, 360.0);
}

double deg_to_180(double deg)
{
  return fmod(fmod(deg + 180.0, 360.0) + 360.0, 360.0) - 180.0;
}

double deg_to_2pi(double deg)
{
  double rad = DEG_TO_RAD(deg);
  return rad_to_2pi(rad);
}

double deg_to_pi(double deg)
{
  double rad = DEG_TO_RAD(deg);
  return rad_to_pi(rad);
}

double rad_to_360(double rad)
{
  double deg = RAD_TO_DEG(rad);
  return deg_to_360(deg);
}

double rad_to_180(double rad)
{
  double deg = RAD_TO_DEG(rad);
  return deg_to_180(deg);
}

double rad_to_2pi(double rad)
{
  return fmod(fmod(rad, 2.0 * M_PI) + 2.0 * M_PI, 2.0 * M_PI);
}

double rad_to_pi(double rad)
{
  return fmod(fmod(rad + M_PI, 2.0 * M_PI) + 2.0 * M_PI, 2.0 * M_PI) - M_PI;
}