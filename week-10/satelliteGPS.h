/***********************************************************************
 * Header File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;

 /****************************************
 * GPSRight
 *    Everything to know about a GPS satellite Right part
 *****************************************/
class GPSRight : public Entity
{
   friend TestSatellite;

public:
   GPSRight() : Entity() 
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }
   GPSRight(const Entity& e) : Entity(e)
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }


   virtual void draw(ogstream& gout) { gout.drawGPSRight(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

 /****************************************
 * GPSLeft
 *    Everything to know about a GPS satellite left part
 *****************************************/
class GPSLeft : public Entity
{
   friend TestSatellite;

public:
   GPSLeft() : Entity() 
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }
   GPSLeft(const Entity& e) : Entity(e)
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }
   

   virtual void draw(ogstream& gout) { gout.drawGPSLeft(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

/****************************************
* GPSCenter
*    Everything to know about a GPS satellite Center
*****************************************/
class GPSCenter : public Entity
{
   friend TestSatellite;

public:
   GPSCenter() : Entity() 
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }
   GPSCenter(const Entity& e) : Entity(e)
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }

   virtual void draw(ogstream& gout) { gout.drawGPSCenter(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

/****************************************
* SateliteGPS
*    Everything to know about a GPS satellite
*****************************************/
class SatelliteGPS : public Satellite
{

   friend TestSatellite;

public:
   SatelliteGPS() : Satellite()
   {
      isBroken = false;
      radius = 12 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }
   SatelliteGPS(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                bool isBroke = false) : Satellite(pos, vel, a , isBroke)
   {
      radius = 12 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout) { gout.drawGPS(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move

};

