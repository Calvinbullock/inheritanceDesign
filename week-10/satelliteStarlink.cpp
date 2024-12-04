/***********************************************************************
 * Source File:
 *    SatelliteStarlink class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Starlink satellite
 ************************************************************************/

#include "satelliteStarlink.h"
#include "fragments.h"
#include <iostream>

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlink::impact(std::vector<Entity*> &entities)
{
   std::cout << "Kaboom1" << std::endl;
   int fragCount = 4; // temp value
   isBroken = true;

   entities.push_back(new SatelliteStarlinkBody(position, velocity, angle));
   entities.push_back(new SatelliteStarlinkArray(position, velocity, angle));
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlinkArray::impact(std::vector<Entity*> &entities)
{}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlinkBody::impact(std::vector<Entity*> &entities)
{}
