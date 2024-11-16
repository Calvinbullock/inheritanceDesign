
#define _USE_MATH_DEFINES

#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI
#include "position.h"   // for position

/******************************************************************
* GET GRAVITY : magnitude of acceleration due to gravity at an altitude
*
* gh = magnitude of acceleration due to gravity at an altitude(h)
* g = gravity at sea level : 9.80665 m / s2
* r = radius of the earth : 6, 378, 000 m
* h = height above the earth in meters

* gh = g * ((r/(r+h)) * (r/(r+h)))
*********************************************************/
inline double getGravity(double g, double r, double h)
{
   return g * ((r / (r + h)) * (r / (r + h)));
}

/****************************************************
* GET DIRECTION GRAVITY: direction of the pull of gravity, in radians
*
* xe = horizontal position of the center of the earth: 0 m
* ye = vertical position of the center of the earth: 0 m
* xs = horizontal position of the satellite in meters
* ys = vertical position of the satellite in meters
*
* d = atan(xe - xs, ye - ys)
*****************************************************/
inline double getDirectionGravity(Position earthCenter, Position satPos)
{
   return atan2(earthCenter.getMetersX() - satPos.getMetersX(),
                earthCenter.getMetersY() - satPos.getMetersY() );
}

