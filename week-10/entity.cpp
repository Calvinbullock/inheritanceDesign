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
void Entity::orbit(double time)
{
   Acceleration aGravity = getGravity(position);
   
   std::cout << aGravity.getDDX() << std::endl;
   std::cout << aGravity.getDDY() << std::endl;

   velocity.add(aGravity, time / 2.0);
   position.add(aGravity, velocity, time);
   velocity.add(aGravity, time / 2.0);

}

/*********************************************
* SATELLITE ROTATE
*********************************************/
void Entity::rotate(double delta)
{
   angle.add(delta);
}
