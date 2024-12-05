
/***********************************************************************
 * Source File:
 *    Fragment class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about Fragment's
 ************************************************************************/

#pragma once

#include "entity.h"
#include "acceleration.h"

/***********************************************************************
 * Fragment
 *    Everything to know about Fragment's
 ************************************************************************/
class Fragment: public Entity
{

public:
   // Constructors
   Fragment() : Entity() {}
   Fragment(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout) { gout.drawFragment(position, angle.getRadians()); }
   virtual void impact(std::vector<Entity*>& entities) {}

protected:
};
