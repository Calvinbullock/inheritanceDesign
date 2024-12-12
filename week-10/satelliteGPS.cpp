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
   isBroken = true;
   Velocity explosionVelocity;

   for (int i = 0; i < fragmentCount; i++)
   {
      explosionVelocity.set(random(0.0, 360.0), EXPLOSION_SPEED);
      entities.push_back(new Fragment(position, explosionVelocity, angle));
   }
}
/****************************************
* IMPACT - GPS LEFT
* What happens on impact?
*****************************************/
void GPSLeft::impact(std::vector<Entity*> &entities)
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
* IMPACT - GPS CENTER
* What happens on impact?
*****************************************/
void GPSCenter::impact(std::vector<Entity*> &entities)
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
* IMPACT - SATELLITE GPS
* What happens on impact?
*****************************************/
void SatelliteGPS::impact(std::vector<Entity*> &entities)
{
   // TODO: fix pos, allow parts to be seen.
   //    CLean up a bit

   if (isBroken)
   {
      return;
   }

   this->isBroken = true;

   // TODO: fix speed and direction add

   Velocity explosionVelocity;
   Position pos(this->position);
   //Position pos2(0.0, 26565000.0);

   explosionVelocity.set(90.0, EXPLOSION_SPEED);
   pos.addDirection(90.0, 10000.0);
   entities.push_back(new GPSCenter(pos, explosionVelocity, this->angle));

   explosionVelocity.set(0.0, EXPLOSION_SPEED);
   pos.addDirection(0.0, 1000.0);
   entities.push_back(new GPSLeft(pos, explosionVelocity, this->angle));

   explosionVelocity.set(180.0, EXPLOSION_SPEED);
   pos.addDirection(180.0, 1000.0);
   entities.push_back(new GPSRight(pos, explosionVelocity, this->angle));
}
