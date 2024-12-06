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
   this->isBroken = true;

   Velocity explosionVelocity;

   for (int i = 0; i < FRAG_COUNT; i++)
   {
      explosionVelocity.set(randomDegreesGen(), EXPLOSION_SPEED);
      entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   }

   //for (double degrees = 0.0; degrees < 360.0; degrees += 120.0) // 3 fragments
   //{
   //   explosionVelocity.set(degrees, EXPLOSION_SPEED);
   //   entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   //}
}
/****************************************
* IMPACT - GPS LEFT
* What happens on impact?
*****************************************/
void GPSLeft::impact(std::vector<Entity*> &entities)
{
   this->isBroken = true;
   
   Velocity explosionVelocity;

   for (int i = 0; i < FRAG_COUNT; i++)
   {
      explosionVelocity.set(randomDegreesGen(), EXPLOSION_SPEED);
      entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   }

   //for (double degrees = 0.0; degrees < 360.0; degrees += 120.0) // 3 fragments
   //{
   //   explosionVelocity.set(degrees, EXPLOSION_SPEED);
   //   entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   //}
}
/****************************************
* IMPACT - GPS CENTER
* What happens on impact?
*****************************************/
void GPSCenter::impact(std::vector<Entity*> &entities)
{
   this->isBroken = true;

   Velocity explosionVelocity;

   for (int i = 0; i < FRAG_COUNT; i++)
   {
      explosionVelocity.set(randomDegreesGen(), EXPLOSION_SPEED);
      entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   }

   //for (double degrees = 0.0; degrees < 360.0; degrees += 120.0) // 3 fragments
   //{
   //   explosionVelocity.set(degrees, EXPLOSION_SPEED);
   //   entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   //}
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

   Velocity explosionVelocity;
   Position pos(this->position);

   
   explosionVelocity.set(90.0, EXPLOSION_SPEED);
   pos.addMetersX(100.0);
   entities.push_back(new GPSCenter(pos, explosionVelocity, this->angle));
   explosionVelocity.set(0.0, EXPLOSION_SPEED);
   pos.addMetersX(-20.0);
   entities.push_back(new GPSLeft(pos, explosionVelocity, this->angle));
   explosionVelocity.set(180.0, EXPLOSION_SPEED);
   pos.addMetersY(10.0);
   entities.push_back(new GPSRight(pos, explosionVelocity, this->angle));

   for (double degrees = 0.0; degrees < 360.0; degrees += 180.0) // 2 fragments
   {
      std::cout << degrees << std::endl;
      explosionVelocity.set(degrees, EXPLOSION_SPEED);
      entities.push_back(new Fragment(this->position, explosionVelocity, this->angle));
   }
}
