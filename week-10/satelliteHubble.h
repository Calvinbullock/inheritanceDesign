/***********************************************************************
 * Header File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite
 ************************************************************************/

#pragma once

#include "satellite.h"

/****************************************
* SateliteHubble
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubble : public Satellite
{
public:
   SatelliteHubble() : Satellite() {}
   SatelliteHubble(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) \
   {
      this->radius = 10 * this->position.getZoom();
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubble(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* SateliteHubbleTelescope
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleTelescope : public Satellite
{
public:
   SatelliteHubbleTelescope() : Satellite() {}
   SatelliteHubbleTelescope(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleTelescope(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* SateliteHubbleLeft
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleLeft : public Satellite
{
public:
   SatelliteHubbleLeft() : Satellite() {}
   SatelliteHubbleLeft(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleLeft(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* SateliteHubbleRight
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleRight : public Satellite
{
public:
   SatelliteHubbleRight() : Satellite() {}
   SatelliteHubbleRight(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleRight(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* SateliteHubbleComputer
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleComputer : public Satellite
{
public:
   SatelliteHubbleComputer() : Satellite() {}
   SatelliteHubbleComputer(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Satellite(pos, vel, a , isBroke) {}

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleComputer(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
};
