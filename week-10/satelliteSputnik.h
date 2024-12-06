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
   SatelliteSputnik(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                    bool isBroke = false) : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 4 * this->position.getZoom();
      fragmentCount = 4;
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout) { gout.drawSputnik(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

