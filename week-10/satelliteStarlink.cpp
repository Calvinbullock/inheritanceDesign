/***********************************************************************
 * Source File:
 *    SatelliteStarlink class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Starlink satellite
 ************************************************************************/

#include "satelliteStarlink.h"
#include "fragment.h"
#include "velocity.h"

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlink::impact(std::vector<Entity*> &entities)
{
   isBroken = true;

   entities.push_back(new SatelliteStarlinkBody(*this));
   entities.push_back(new SatelliteStarlinkArray(*this));

   Velocity explosionVelocity;
   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlinkArray::impact(std::vector<Entity*> &entities)
{
   isBroken = true;
   Velocity explosionVelocity;

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlinkBody::impact(std::vector<Entity*> &entities)
{
   isBroken = true;
   Velocity explosionVelocity;

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}
