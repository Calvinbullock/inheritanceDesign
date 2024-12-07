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

/***************************************************************
 * INPUT
 * update position and velocity based on user input
 ***************************************************************/
void Entity::input(const Interface* pUI, std::vector<Entity*>& entities, const double &time)
{
   if (pUI->isSpace())
   {
      Velocity fireVelocity;
      fireVelocity.set(angle, velocity.getSpeed() + PROJ_SPEED);

      entities.push_back(new Projectile(ship.getPosition(), fireVelocity, ship.getAngle()));
   }

   // main engines
   if (thrust.isMain())
   {
      Acceleration a;

      a.addDDX(-sin(angle.getRadians()) * SHIP_THRUST);
      a.addDDY(cos(angle.getRadians()) * SHIP_THRUST);
      a.reverseDDX();

      velocity.add(a, time);
   }

   // clockwise
   if (thrust.isClock())
   {
      angle.add(SHIP_ROTATION);
   }
   // counter clockwise
   if (thrust.isCounter())
   {
      angle.add(-SHIP_ROTATION);
   }

   this->thrust.set(pUI);
}
