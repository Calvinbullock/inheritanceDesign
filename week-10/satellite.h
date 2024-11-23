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
#include "thrust.h"

#define SHIP_THRUST 2      // m/sec^2
//#define SHIP_THRUST 96     // m/sec
#define SHIP_ROTATION 0.1  // radians

/***********************************************************************
 * Entity
 *    Everything to know about satellite's
 ************************************************************************/
class Satellite : public Entity
{
public:

   // Constructors
   Satellite() : Entity() {}
   Satellite(Position& pos, Velocity& vel, Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke), thrust() {}

   virtual void draw(ogstream& gout) { assert(false); }
   virtual void impact() { assert(false); }

   void input(const Thrust &t, double gravity, const int &time);

   // TODO: Do we need this?
   //void initialize(Position pos, Velocity vel, Angle a)
   //{
   //   position = pos;
   //   velocity = vel;
   //   angle = a;
   //}

protected:
   int fragmentCount;
   Thrust thrust;
};
