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
#define RADIUS_EARTH 6378000.0    // m | Also earth's surface

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
   return atan2(earthCenter.getMetersX() - satPos.getMetersX(),
                earthCenter.getMetersY() - satPos.getMetersY());
}

 // atan2 needs y and sat first
 //inline double getDirectionGravity(Position earthCenter, Position satPos)
//{  
//   return atan2(satPos.getMetersY() - earthCenter.getMetersY(),
//                satPos.getMetersX() - earthCenter.getMetersX());
//}

// zero is up
//inline double getDirectionGravity(Position earthCenter, Position satPos)
//{
//   double dx = satPos.getMetersX() - earthCenter.getMetersX();
//   double dy = satPos.getMetersY() - earthCenter.getMetersY();
//
//   double angle = atan2(dy, dx);
//
//   // Adjust the angle to match your rotated coordinate system
//   angle -= M_PI / 2;  // Subtract ?/2 to shift 0 radians to the top (positive Y-axis)
//
//   Angle a;
//   a.setRadians(angle); // normalize
//   
//   return a.getRadians();
//}


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
   double h = computeDistance(Position(), satPos); //distance from earth center

   // Don't need to add r because we cover that in computeDistance
   double gravity =  g * ((r / h) * (r / h));

   std::cout << "gravity: " << gravity << std::endl;

   Angle gravityAngle;
   double gravityAngleRadians = getDirectionGravity(Position(), satPos);
   gravityAngle.setRadians(gravityAngleRadians);

   std::cout << "angle: " << gravityAngle.getRadians() << std::endl;

   Acceleration aGravity;
   aGravity.set(gravityAngle, gravity);

   return aGravity;
   
}


