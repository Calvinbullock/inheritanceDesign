/***********************************************************************
 * Source File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite's
 ************************************************************************/

#include "satelliteHubble.h"
#include "fragments.h"

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubble::impact(std::vector<Entity*> &entities)
{
   int fragCount = 4; // temp value
   isBroken = true;

   entities.push_back(new SatelliteHubbleLeft(position, velocity, angle));
   entities.push_back(new SatelliteHubbleRight(position, velocity, angle));
   entities.push_back(new SatelliteHubbleTelescope(position, velocity, angle));
   entities.push_back(new SatelliteHubbleComputer(position, velocity, angle));
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleLeft::impact(std::vector<Entity*> &entities)
{
   int fragCount = 2; // temp value
   isBroken = true;

   for (int i = 0; i < fragCount; i++)
   {
      entities.push_back(new Fragment(position, velocity, angle));
   }
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleRight::impact(std::vector<Entity*> &entities)
{
   int fragCount = 2; // temp value
   isBroken = true;

   for (int i = 0; i < fragCount; i++)
   {
      entities.push_back(new Fragment(position, velocity, angle));
   }
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleComputer::impact(std::vector<Entity*> &entities)
{
   int fragCount = 2; // temp value
   isBroken = true;

   for (int i = 0; i < fragCount; i++)
   {
      entities.push_back(new Fragment(position, velocity, angle));
   }
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleTelescope::impact(std::vector<Entity*> &entities)
{
   int fragCount = 2; // temp value
   isBroken = true;

   for (int i = 0; i < fragCount; i++)
   {
      entities.push_back(new Fragment(position, velocity, angle));
   }
}
