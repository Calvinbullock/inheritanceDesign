/***********************************************************************
 * Header File:
 *    SatelliteStarlink class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Starlink satellite
 ************************************************************************/

#pragma once

#include "entity.h"
#include "satellite.h"

class TestSatellite;

 /****************************************
 * SateliteGPS
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlink : public Satellite
{
   friend TestSatelliteShip;

public:
   SatelliteStarlink() : Satellite()
   {
      isBroken = false;
      fragmentCount = 2;
      radius = 6 * position.getZoom();
   }
   SatelliteStarlink(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                     bool isBroke = false) : Satellite(pos, vel, a, isBroke)
   {
      radius = 6 * position.getZoom();
      fragmentCount = 2;
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawStarlink(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

 /****************************************
 * SateliteGPSBody
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlinkBody : public Entity
{
public:
   SatelliteStarlinkBody() : Entity() {}
   SatelliteStarlinkBody(const Entity& e) : Entity(e)
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawStarlinkBody(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};


 /****************************************
 * SateliteGPSArray
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlinkArray : public Entity
{
public:
   SatelliteStarlinkArray() : Entity() {}
   SatelliteStarlinkArray(const Entity& e) : Entity(e)
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawStarlinkArray(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};
