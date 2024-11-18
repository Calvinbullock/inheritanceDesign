/***********************************************************************
 * Header File:
 *    SatelliteStarlink class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Starlink satellite
 ************************************************************************/

#pragma once

#include "satellite.h"

 /****************************************
 * SateliteGPS
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlink : public Satellite
{
public:
   SatelliteStarlink() : Satellite() {}
   SatelliteStarlink(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout);
   virtual void impact();
};

