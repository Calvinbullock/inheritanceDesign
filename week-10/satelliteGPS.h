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

//TODO: temp value
const int FRAG_COUNT = 3;

 /****************************************
 * GPSRight
 *    Everything to know about a GPS satellite Right part
 *****************************************/
class GPSRight : public Entity
{
public:
   GPSRight() : Entity() {}
   GPSRight(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      this->radius = 8 * this->position.getZoom();
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
public:
   GPSLeft() : Entity() {}
   GPSLeft(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      this->radius = 8 * this->position.getZoom();
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
public:
   GPSCenter() : Entity() {}
   GPSCenter(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      this->radius = 7 * this->position.getZoom();
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
public:
   SatelliteGPS() : Satellite() {}
   SatelliteGPS(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                bool isBroke = false) : Satellite(pos, vel, a , isBroke)
   {
      this->radius = 12 * this->position.getZoom();
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout) { gout.drawGPS(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move

};

