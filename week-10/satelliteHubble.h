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

/****************************************
* SateliteHubble
*    Everything to know about a Hubble satellite
*****************************************/
class SatelliteHubble : public Satellite
{
public:
   SatelliteHubble() : Satellite() 
   {
      isBroken = false;
      this->radius = 10 * this->position.getZoom();
      fragmentCount = 0;
   }
   SatelliteHubble(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                   bool isBroke = false) : Satellite(pos, vel, a , isBroke)
   {
      this->radius = 10 * this->position.getZoom();
      fragmentCount = 0;
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
public:
   SatelliteHubbleTelescope() : Entity() {}
   SatelliteHubbleTelescope(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Entity(pos, vel, a , isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      double magnitude = random(5000, 9000);
      Velocity randVel;
      randVel.set(a, magnitude);
      velocity += randVel += vel;

      radius = 10 * position.getZoom();
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
public:
   SatelliteHubbleLeft() : Entity() {}
   SatelliteHubbleLeft(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Entity(pos, vel, a , isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      double magnitude = random(5000, 9000);
      Velocity randVel;
      randVel.set(a, magnitude);
      velocity += randVel += vel;

      radius = 7 * position.getZoom();
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
public:
   SatelliteHubbleRight() : Entity() {}
   SatelliteHubbleRight(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Entity(pos, vel, a , isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      double magnitude = random(5000, 9000);
      Velocity randVel;
      randVel.set(a, magnitude);
      velocity += randVel += vel;

      radius = 8 * position.getZoom();
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
public:
   SatelliteHubbleComputer() : Entity() {}
   SatelliteHubbleComputer(Position& pos, Velocity& vel,
                Angle& a, bool isBroke = false)
               : Entity(pos, vel, a , isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      double magnitude = random(5000, 9000);
      Velocity randVel;
      randVel.set(a, magnitude);
      velocity += randVel += vel;

      radius = 8 * position.getZoom();
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout)
   {
      gout.drawHubbleComputer(position, angle.getRadians());
   }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust &t, const double &time) {}
};
