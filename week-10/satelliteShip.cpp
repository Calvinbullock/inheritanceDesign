/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "satelliteShip.h"
#include "velocity.h"

/****************************************
* IMPACT
* What happens on impact?
*****************************************/
void SatelliteShip::impact(std::vector<Entity*> &entities)
{
   isBroken = true;

   Velocity explosionVelocity;
   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
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
      fireVelocity.set(angle, PROJ_SPEED);
      Position shipFront(this->position);
      ogstream gout;
      shipFront = gout.getShipFront(this->position, 0.0, 19.0, this->angle.getRadians());

      entities.push_back(new Projectile(shipFront, fireVelocity, this->angle));

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
