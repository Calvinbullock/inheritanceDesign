/***********************************************************************
 * Header File:
 *    Satellite Ship class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Ship Entity
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "satellite.h"
#include "thrust.h"

#define SHIP_THRUST 2      // m/sec^2
//#define SHIP_THRUST 96     // m/sec
#define SHIP_ROTATION 0.1  // radians

 /****************************************
 * SateliteShip
 *    Everything to know about a ship satellite
 *****************************************/
class SatelliteShip : public Satellite
{

public:
   SatelliteShip() : Satellite() {}
   SatelliteShip(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
         : Satellite(pos, vel, a, isBroke), thrust() {}

   virtual void draw(ogstream& gout) { gout.drawShip(position, angle.getRadians(), thrust.isMain()); }
   virtual void impact();

   Acceleration input(const Thrust &t, double gravity);

private:
   Thrust thrust;
};
