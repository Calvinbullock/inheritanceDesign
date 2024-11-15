#pragma once

#include "satellite.h"

class SatelliteGPS : public Satellite
{
public:
   SatelliteGPS() : Satellite() {}
   SatelliteGPS(Position& pos, Velocity& vel, Angle& a, bool isBroke = false) : Satellite(pos, vel, a , isBroke) {}


   virtual void draw(ogstream& gout);
   virtual void impact();

private:

   // Inherited Attributes
   // Position pos;
   // Velocity vel;
   // Angle angle;
   // bool isBroken;
   // double width;

};

