/***********************************************************************
 * Source File:
 *    Entity
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    Everything we need to know about a Entity
 ************************************************************************/

#include "entity.h"
#include <math.h>

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



