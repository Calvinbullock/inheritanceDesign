/***********************************************************************
 * Source File:
 *    Satellite class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about satellite's
 ************************************************************************/

#pragma once

#include "entity.h"
#include "acceleration.h"
#include "fragment.h"
#include "uiDraw.h"

class TestSatellite;

/***********************************************************************
 * Entity
 *    Everything to know about satellite's
 ************************************************************************/
class Satellite : public Entity
{

friend TestSatellite;

public:
   // Constructors
   Satellite() : Entity() {}
   Satellite(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke) {}

   virtual void defunctChance(int i) {
      if (isDefunct) { return; }
      isDefunct = 0 == random(0, chanceDefunct);
   }

   virtual void defunct(int randNum) 
   {
      isDefunct = randNum == 0;
   }

   virtual void draw(ogstream& gout) { assert(false); }
   virtual void impact(std::vector<Entity*> &entities) { assert(false); }

protected:
};
