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

   virtual void draw(ogstream& gout)
   {
      gout.drawHubble(position, angle.getRadians());
   }
   virtual void impact();
};

 /****************************************
 * SateliteGPSBody
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlinkBody : public Satellite
{
public:
   SatelliteStarlinkBody() : Satellite() {}
   SatelliteStarlinkBody(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawStarlinkBody(position, angle.getRadians());
   }
   virtual void impact();
};


 /****************************************
 * SateliteGPSArray
 *    Everything to know about a Starlink satellite
 *****************************************/
class SatelliteStarlinkArray : public Satellite
{
public:
   SatelliteStarlinkArray() : Satellite() {}
   SatelliteStarlinkArray(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawStarlinkArray(position, angle.getRadians());
   }
   virtual void impact();
};
