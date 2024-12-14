/***********************************************************************
 * Header File:
 *    SatelliteDragon class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Dragon satellite
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestSatellite;

/****************************************
* DragonRight
*    Everything to know about a Dragon Right Part
*****************************************/
class DragonRight : public Entity
{
   friend TestSatellite;

public:
   DragonRight() : Entity() {}
   DragonRight(Position& pos, Velocity& vel, Angle& a,  bool isBroke = false)
               : Entity(pos, vel, a, isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      breakApartVel(a, vel);

      radius = 6 * position.getZoom();
      fragmentCount = 2;
   }
   DragonRight(const Entity& e) : Entity(e)
   {
      radius = 6 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonRight(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

/****************************************
* DragonLeft
*    Everything to know about a Dragon Left Part
*****************************************/
class DragonLeft : public Entity
{
   friend TestSatellite;

public:
   DragonLeft() : Entity() {}
   DragonLeft(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      breakApartVel(a, vel);

      radius = 6 * position.getZoom();
      fragmentCount = 2;
   }
   DragonLeft(const Entity& e) : Entity(e)
   {
      radius = 6 * position.getZoom(); // pixels to meters
      fragmentCount = 2;
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonLeft(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

/****************************************
* DragonCenter
*    Everything to know about a Dragon Center Part
*****************************************/
class DragonCenter : public Entity
{
   friend TestSatellite;

public:
   DragonCenter() : Entity() {}
   DragonCenter(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      // new velocity should increase between 5,000 - 9,000 m/s
      breakApartVel(a, vel);

      radius = 6 * position.getZoom();
      fragmentCount = 4;
   }
   DragonCenter(const Entity& e) : Entity(e)
   {
      radius = 6 * position.getZoom(); // pixels to meters
      fragmentCount = 4;
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonCenter(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

 /****************************************
 * SateliteDragon
 *    Everything to know about a Dragon satellite
 *****************************************/
class SatelliteDragon : public Satellite
{

   friend TestSatellite;

public:
   SatelliteDragon() : Satellite()
   {
      isBroken = false;
      radius = 7 * position.getZoom();
      fragmentCount = 2;
   }
   SatelliteDragon(Position& pos, Velocity& vel, Angle& a, int setChanceDefunct,
                   bool isBroke = false) : Satellite(pos, vel, a, isBroke)
   {
      radius = 7 * position.getZoom();
      fragmentCount = 2;
      isDefunct = false;
      chanceDefunct = setChanceDefunct;
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragon(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
   virtual void input(const Thrust& t, const double& time) {} // remove if you want to move
};

