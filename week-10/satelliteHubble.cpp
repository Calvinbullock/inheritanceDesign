/***********************************************************************
 * Source File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite's
 ************************************************************************/

#include "satelliteHubble.h"

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubble::impact(std::vector<Entity*> &entities)
{
   std::cout << "Kaboom" << std::endl;
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
{}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleRight::impact(std::vector<Entity*> &entities)
{}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleComputer::impact(std::vector<Entity*> &entities)
{}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubbleTelescope::impact(std::vector<Entity*> &entities)
{}
