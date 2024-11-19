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

/***********************************************************************
 * Entity
 *    Everything to know about satellite's
 ************************************************************************/
class Satellite : public Entity
{
public:

   // Constructors
   Satellite() : Entity() {}
   Satellite(Position& pos, Velocity& vel, Angle& a, bool isBroke = false) : Entity(pos, vel, a, isBroke) {}

   virtual void draw(ogstream& gout) { assert(false); }
   virtual void impact() { assert(false); }
   // TODO: Do we need this?
   //void initialize(Position pos, Velocity vel, Angle a)
   //{
   //   position = pos;
   //   velocity = vel;
   //   angle = a;
   //}

protected:
   int fragmentCount;
};
