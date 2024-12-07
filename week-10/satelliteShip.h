/***********************************************************************
 * Header File:
 *    Satellite Ship class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Ship Satellite
 ************************************************************************/

#pragma once

#include "satellite.h"
#include "projectile.h"

class TestSatelliteShip;

 /****************************************
 * SateliteShip
 *    Everything to know about a Ship Satellite
 *****************************************/
class SatelliteShip : public Satellite
{

   friend TestSatelliteShip;

public:
   SatelliteShip() : Satellite() 
   {
      isBroken = false;
      fragmentCount = 5;
      radius = 10 * position.getZoom(); // pixels to meters
   }
   SatelliteShip(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
         : Satellite(pos, vel, a, isBroke)
   {
      fragmentCount = 5;
      radius = 10 * position.getZoom(); // pixels to meters
   }

   virtual void draw(ogstream& gout) { gout.drawShip(position, angle.getRadians(), thrust.isMain()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Interface* pUI, std::vector<Entity*>& entities, const double& time);

private:
};
