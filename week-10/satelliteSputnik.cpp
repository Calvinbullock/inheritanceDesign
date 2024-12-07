/***********************************************************************
 * Source File:
 *    SatelliteSputnik class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Sputnik satellite
 ************************************************************************/

#include "satelliteSputnik.h"

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteSputnik::impact(std::vector<Entity*> &entities)
{
   isBroken = true;
   Velocity explosionVelocity;

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}
