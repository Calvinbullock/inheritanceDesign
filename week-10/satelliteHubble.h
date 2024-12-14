/***********************************************************************
 * Header File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite
 ************************************************************************/

#pragma once

#include "entity.h"
#include "satellite.h"

class TestSatellite;

/****************************************
* SateliteHubble
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubble : public Satellite
{
   friend TestSatellite;

public:
   SatelliteHubble() : Satellite()
   {
      isBroken = false;
      this->radius = 10 * this->position.getZoom();
      fragmentCount = 4;
   }
   SatelliteHubble(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                   bool isBroke = false) : Satellite(pos, vel, a , isBroke)
   {
      this->radius = 10 * this->position.getZoom();
      fragmentCount = 4;
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubble(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

/****************************************
* SateliteHubbleTelescope
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleTelescope : public Entity
{
   friend TestSatellite;

public:
   SatelliteHubbleTelescope() : Entity() 
   {
      radius = 10 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }
   SatelliteHubbleTelescope(const Entity& e) : Entity(e)
   {
      radius = 10 * position.getZoom(); // pixels to meters
      fragmentCount = 3;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleTelescope(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

/****************************************
* SateliteHubbleLeft
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleLeft : public Entity
{
   friend TestSatellite;

public:
   SatelliteHubbleLeft() : Entity() 
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }
   SatelliteHubbleLeft(const Entity& e) : Entity(e)
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleLeft(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

/****************************************
* SateliteHubbleRight
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleRight : public Entity
{
   friend TestSatellite;

public:
   SatelliteHubbleRight() : Entity() 
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }
   SatelliteHubbleRight(const Entity& e) : Entity(e)
   {
      radius = 8 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleRight(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};

/****************************************
* SateliteHubbleComputer
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubbleComputer : public Entity
{
   friend TestSatellite;

public:
   SatelliteHubbleComputer() : Entity() 
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }
   SatelliteHubbleComputer(const Entity& e) : Entity(e)
   {
      radius = 7 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleComputer(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};
