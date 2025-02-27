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
   radius(e.radius)
{
   // new velocity should increase between 1,000 - 3,000 m/s
   double magnitude = random(1000, 3000);

   // Adjust the position slightly to add a "kick"
   Position posKick;
   posKick.setPixelsX(10.0 * sin(random(0.0, 360.0)));
   posKick.setPixelsY(10.0 * cos(random(0.0, 360.0)));
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
