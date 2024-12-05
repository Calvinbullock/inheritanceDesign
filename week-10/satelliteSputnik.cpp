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
   int fragCount = 4; // temp value
   isBroken = true;

   for (int i = 0; i < fragCount; i++)
   {
      entities.push_back(new Fragment(position, velocity, angle));
   }
}
