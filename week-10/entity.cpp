/***********************************************************************
 * Source File:
 *    Entity
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    Everything we need to know about a Entity
 ************************************************************************/

#include "entity.h"
#include "uiDraw.h"
#include <math.h>

/*********************************************
* ENTITY COPY CONSTRUCTOR
*********************************************/
Entity::Entity(const Entity& e)
   : thrust(),
   isDefunct(false),
   chanceDefunct(),
   fragmentCount(),
   position(e.position),
   velocity(e.velocity),
   angle(e.angle),
   isBroken(false),
   radius(e.radius),
   isTest(false)
{
   // new velocity should increase between 1,000 - 3,000 m/s
   double magnitude;
   double kickAngle;

   // FOR TESTING
   if (isTest)
   {
      magnitude = 3000.0;
      kickAngle = 0.0;
   }
   else
   {
      magnitude = random(1000, 3000);
      kickAngle = random(0.0, 360.0);
   }

   Velocity kick;
   kick.set(angle, magnitude);
   velocity += kick;

   // Adjust the position slightly to add a "kick"
   Position posKick;
   posKick.setPixelsX(10.0 * sin(kickAngle));
   posKick.setPixelsY(10.0 * cos(kickAngle));
   position.addMetersX(posKick.getMetersX());
   position.addMetersY(posKick.getMetersY());
}

/*********************************************
* SATELLITE ORBIT
* Handles the satellite orbit calculations
*********************************************/
void Entity::orbit(double time, Acceleration accel)
{
   position.add(accel, velocity, time);
   velocity.add(accel, time);
}

/*********************************************
* SATELLITE ROTATE
*********************************************/
void Entity::rotate(double delta)
{
   angle.add(delta);
}
