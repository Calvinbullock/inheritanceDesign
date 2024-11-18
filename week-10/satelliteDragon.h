/***********************************************************************
 * Header File:
 *    SatelliteDragon class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Dragon satellite
 ************************************************************************/

#pragma once

#include "satellite.h"

 /****************************************
 * SateliteGPS
 *    Everything to know about a Dragon satellite
 *****************************************/
class SatelliteDragon : public Satellite
{
public:
   SatelliteDragon() : Satellite() {}
   SatelliteDragon(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout);
   virtual void impact();
};

