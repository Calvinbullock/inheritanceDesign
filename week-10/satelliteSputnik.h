/***********************************************************************
 * Header File:
 *    Satellite Sputnik class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#pragma once

#include "satellite.h"

 /****************************************
 * SateliteSputnik
 *    Everything to know about a Sputnik satellite
 *****************************************/
class SatelliteSputnik : public Satellite
{
public:
   SatelliteSputnik() : Satellite() {}
   SatelliteSputnik(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke) 
   {
      this->radius = 4;    
   }

   virtual void draw(ogstream& gout) { gout.drawSputnik(position, angle.getRadians()); }
   virtual void impact();
};

