/***********************************************************************
 * Source File:
 *    SatelliteDragon class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Dragon satellite
 ************************************************************************/

#include "satelliteDragon.h"

/****************************************
* IMPACT - DRAGON RIGHT
* What happens on impact?
*****************************************/
void DragonRight::impact(std::vector<Entity*> &entities)
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
* IMPACT - DRAGON LEFT
* What happens on impact?
*****************************************/
void DragonLeft::impact(std::vector<Entity*> &entities)
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
* IMPACT - DRAGON CENTER
* What happens on impact?
*****************************************/
void DragonCenter::impact(std::vector<Entity*> &entities)
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
* IMPACT - SATELLITE DRAGON
* What happens on impact?
*****************************************/
void SatelliteDragon::impact(std::vector<Entity*> &entities)
{
   this->isBroken = true;
   Velocity explosionVelocity;

   entities.push_back(new DragonCenter(*this));
   entities.push_back(new DragonLeft(*this));
   entities.push_back(new DragonRight(*this));

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}

