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

 /****************************************
 * GPSRight
 *    Everything to know about a GPS satellite Right part
 *****************************************/
class GPSRight : public Satellite
{
public:
   GPSRight() : Satellite() {}
   GPSRight(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 8; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawGPSRight(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

 /****************************************
 * GPSLeft
 *    Everything to know about a GPS satellite left part
 *****************************************/
class GPSLeft : public Satellite
{
public:
   GPSLeft() : Satellite() {}
   GPSLeft(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 8; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawGPSLeft(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* GPSCenter
*    Everything to know about a GPS satellite Center
*****************************************/
class GPSCenter : public Satellite
{
public:
   GPSCenter() : Satellite() {}
   GPSCenter(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 7; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawGPSCenter(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* SateliteGPS
*    Everything to know about a GPS satellite
*****************************************/
class SatelliteGPS : public Satellite
{
public:
   SatelliteGPS() : Satellite() {}
   SatelliteGPS(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke)
   {
      this->radius = 12 * this->position.getZoom(); // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawGPS(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

