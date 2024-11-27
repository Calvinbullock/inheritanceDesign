/***********************************************************************
 * Header File:
 *    Entity class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything we need to know about Entity
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "position.h"
#include "uiDraw.h"
#include "velocity.h"
#include "angle.h"
#include <cassert>

class TestEntity;

/***********************************************************************
 * Entity
 *    Everything we need to know about Entity
 ************************************************************************/
class Entity
{
public:
   friend TestEntity;

   // Constructors
   // TEMP width TODO:
   Entity() {}
   Entity(Position& pos, Velocity& vel, Angle& a, bool isBroke = false, double r = 10.0)
   {
      position = pos;
      velocity = vel;
      angle = a;
      isBroken = isBroke;
      radius = r;
   }

   // Getters
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   bool     getIsBroken() const { return isBroken; }
   double   getRadius()   const { return radius;   }
   Angle    getAngle()    const { return angle;    }

   // Setters
   void setPosition  (const Position& newPos) { position = newPos;  }
   void setVelocity  (const Velocity& newVel) { velocity = newVel;  }
   void setIsBroken  (bool broken)            { isBroken = broken;  }
   void setAngle     (const Angle& newAngle)  { angle = newAngle;   }
   void setRadius    (double newRadius)       { radius = newRadius; }
   //void setRadiusPixels(double pixelRadius)   { radius = pixelRadius * position.get}

   void orbit(double time, Acceleration accel);
   virtual void rotate(double delta);
   virtual void draw(ogstream& gout) = 0;
   virtual void impact() = 0;

protected:
   Position position;
   Velocity velocity;
   Angle angle;
   bool isBroken;
   double radius;
};

/***************************************************
 * ENTITY DERIVED
 * A simple derived class so we can test Entity.
 ***************************************************/
class EntityDerived : public Entity
{
public:
   EntityDerived() {}
   EntityDerived(Position& pos, Velocity& vel, Angle& a,
                  bool isBroke = false, double w = 10.0)
                  : Entity(pos, vel, a) {}

   virtual void rotate(double delta)           {assert(false);}
   virtual void draw(ogstream& gout)           {assert(false);}
   virtual void impact()                       {assert(false);}
};

