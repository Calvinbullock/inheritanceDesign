/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "satelliteGPS.h"


/****************************************
* IMPACT - GPS RIGHT
* What happens on impact?
*****************************************/
void GPSRight::impact(std::vector<Entity*> &entities)
{
   //this->isBroken = true;
   // TODO:
}
/****************************************
* IMPACT - GPS LEFT
* What happens on impact?
*****************************************/
void GPSLeft::impact(std::vector<Entity*> &entities)
{
   //this->isBroken = true;
   // TODO:
}
/****************************************
* IMPACT - GPS CENTER
* What happens on impact?
*****************************************/
void GPSCenter::impact(std::vector<Entity*> &entities)
{
   //this->isBroken = true;
   // TODO:
}
/****************************************
* IMPACT - SATELLITE GPS
* What happens on impact?
*****************************************/
void SatelliteGPS::impact(std::vector<Entity*> &entities)
{
   if (isBroken)
   {
      return;
   }
   
   this->isBroken = true;

   entities.push_back(new GPSCenter(this->position, this->velocity, this->angle));
   entities.push_back(new GPSLeft(this->position, this->velocity, this->angle));
   entities.push_back(new GPSRight(this->position, this->velocity, this->angle));

   for (double degrees = 0.0; degrees <= 360.0; degrees += 90.0)
   {
      //entities.push_back(new Fragment(this->position, this->velocity, this->angle));
   }
}
