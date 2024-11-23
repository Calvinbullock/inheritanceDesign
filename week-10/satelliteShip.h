/***********************************************************************
 * Header File:
 *    Satellite Ship class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Ship Entity
 ************************************************************************/

#pragma once

#include "satellite.h"

 /****************************************
 * SateliteShip
 *    Everything to know about a ship satellite
 *****************************************/
class SatelliteShip : public Satellite
{

public:
   SatelliteShip() : Satellite() {}
   SatelliteShip(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
         : Satellite(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout) { gout.drawShip(position, angle.getRadians(), thrust.isMain()); }
   virtual void impact();

private:
};
