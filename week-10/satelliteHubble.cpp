/***********************************************************************
 * Source File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite's
 ************************************************************************/

#include "satelliteHubble.h"
#include "fragment.h"
#include "uiDraw.h"

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubble::impact(std::vector<Entity*> &entities)
{
   isBroken = true;

   entities.push_back(new SatelliteHubbleLeft(*this));
   entities.push_back(new SatelliteHubbleRight(*this));
   entities.push_back(new SatelliteHubbleTelescope(*this));
   entities.push_back(new SatelliteHubbleComputer(*this));
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleLeft::impact(std::vector<Entity*> &entities)
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
void SatelliteHubbleRight::impact(std::vector<Entity*> &entities)
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
void SatelliteHubbleComputer::impact(std::vector<Entity*> &entities)
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
void SatelliteHubbleTelescope::impact(std::vector<Entity*> &entities)
{
   isBroken = true;
   Velocity explosionVelocity;

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}

