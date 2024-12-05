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

/****************************************
* DragonRight
*    Everything to know about a Dragon Right Part
*****************************************/
class DragonRight : public Satellite
{
public:
   DragonRight() : Satellite() {}
   DragonRight(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 6; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonRight(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* DragonLeft
*    Everything to know about a Dragon Left Part
*****************************************/
class DragonLeft : public Satellite
{
public:
   DragonLeft() : Satellite() {}
   DragonLeft(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 6; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonLeft(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

/****************************************
* DragonCenter
*    Everything to know about a Dragon Center Part
*****************************************/
class DragonCenter : public Satellite
{
public:
   DragonCenter() : Satellite() {}
   DragonCenter(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 6; // pixels
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragonCenter(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

 /****************************************
 * SateliteDragon
 *    Everything to know about a Dragon satellite
 *****************************************/
class SatelliteDragon : public Satellite
{
public:
   SatelliteDragon() : Satellite() {}
   SatelliteDragon(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Satellite(pos, vel, a, isBroke)
   {
      this->radius = 7 * this->position.getZoom(); // pixels
      this->isDefunct = false;
      this->chanceDefunct = 4000;
   }

   virtual void draw(ogstream& gout) { gout.drawCrewDragon(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*> &entities);
};

