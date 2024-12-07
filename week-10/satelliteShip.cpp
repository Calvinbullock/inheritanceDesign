/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "satelliteShip.h"

/****************************************
* IMPACT
* What happens on impact?
*****************************************/
void SatelliteShip::impact(std::vector<Entity*> &entities)
{
   isBroken = true;
}

/***************************************************************
 * INPUT
 * update position and velocity based on user input
 ***************************************************************/
void SatelliteShip::input(const Interface* pUI, std::vector<Entity*>& entities, const double& time)
{
   if (pUI->isSpace())
   {
      Velocity fireVelocity;
      fireVelocity.set(angle, velocity.getSpeed() + PROJ_SPEED);

      entities.push_back(new Projectile(this->position, fireVelocity, this->angle));
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
