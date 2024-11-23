/***********************************************************************
 * Source File:
 *    physics equations
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    physics!
 ************************************************************************/

#pragma once

#define GRAVITY_SEA_LEVEL 9.80665 // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0    // m

#define _USE_MATH_DEFINES

#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI
#include "position.h"   // for position
#include "angle.h"      // for angle


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
   return atan2(satPos.getMetersY() - earthCenter.getMetersY(),
                satPos.getMetersX() - earthCenter.getMetersX());
}


/******************************************************************
* GET GRAVITY : magnitude of acceleration due to gravity at an altitude
*
* gh = magnitude of acceleration due to gravity at an altitude(h)
* g = gravity at sea level : 9.80665 m / s2
* r = radius of the earth : 6, 378, 000 m
* h = height above the earth in meters

* gh = g * ((r/(r+h)) * (r/(r+h)))
* 
* Returns a acceleratin due to gravity
*********************************************************/
inline Acceleration getGravity(Position satPos)
{
   double r = RADIUS_EARTH;
   double g = GRAVITY_SEA_LEVEL;
   double h = computeDistance(Position(), satPos);

   double gravity =  g * ((r / (r + h)) * (r / (r + h)));

   Angle gravityAngle;
   double gravityAngleRadians = getDirectionGravity(Position(), satPos);
   gravityAngle.setRadians(gravityAngleRadians);

   std::cout << "angle: " << gravityAngle.getRadians() << std::endl;

   Acceleration aGravity;
   aGravity.set(gravityAngle, gravity);

   return aGravity;
   
}


