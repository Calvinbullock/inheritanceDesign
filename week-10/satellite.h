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

   virtual void draw(ogstream& gout) { assert(false); }
   virtual void impact() { assert(false); }

protected:
   int fragmentCount;
};
