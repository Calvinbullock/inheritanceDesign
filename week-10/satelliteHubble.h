/***********************************************************************
 * Header File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite's
 ************************************************************************/

#pragma once

#include "satellite.h"

/****************************************
* SateliteHubble
*    Everything to know about a Hubble satellite's
*****************************************/
class SatelliteHubble : public Satellite
{
public:
   SatelliteHubble() : Satellite() {}
   SatelliteHubble(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout);
   virtual void impact();
};

