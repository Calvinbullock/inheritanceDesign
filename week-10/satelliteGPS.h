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
* SateliteGPS
*    Everything to know about a GPS satellite
*****************************************/
class SatelliteGPS : public Satellite
{
public:
   SatelliteGPS() : Satellite() {}
   SatelliteGPS(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout);
   virtual void impact();
};

