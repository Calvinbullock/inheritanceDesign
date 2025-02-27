/***********************************************************************
 * Header File:
 *    Entity class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything we need to know about Entity
 ************************************************************************/

#pragma once

#include <cassert>
#include <vector>
#include <random>

#include "acceleration.h"
#include "position.h"
#include "uiDraw.h"
#include "velocity.h"
#include "angle.h"
#include "thrust.h"

class TestEntity;
class TestSatellite;
class TestSatelliteShip;
class TestSimulator;

#define SHIP_THRUST 2               // m/sec^2
#define SHIP_ROTATION 0.1           // radians
#define EXPLOSION_SPEED 2500.0
#define PROJ_SPEED 9000.0           // m/s
#define EXPLOSION_DISPLACEMENT 4    //pix

/***********************************************************************
 * Entity
 *    Everything we need to know about Entity
 ************************************************************************/
class Entity
{
public:
   friend TestEntity;
   friend TestSatellite;
   friend TestSatelliteShip;
   friend TestSimulator;

   // Constructors
   Entity() : thrust(), isDefunct(), chanceDefunct(), fragmentCount(0),
            position(), velocity(), angle()
   {
      isBroken = false;
      radius = 2.0;    //default
   }
   Entity(Position& pos, Velocity& vel, Angle& a,
          bool isBroke = false, double r = 2.0)
         : thrust(), isDefunct(), chanceDefunct(), fragmentCount()
   {
      position = pos;
      velocity = vel;
      angle = a;
      isBroken = isBroke;
      radius = r;
   }
   Entity(const Entity& e);

   virtual ~Entity() {}

   // Getters
   Position getPosition()  const { return position; }
   Velocity getVelocity()  const { return velocity; }
   bool     getIsBroken()  const { return isBroken; }
   double   getRadius()    const { return radius;   }
   Angle    getAngle()     const { return angle;    }
   bool     getIsDefunct() const { return isDefunct; }

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
   virtual void impact(std::vector<Entity*> &entities) = 0;

   virtual void input(const Interface* pUI, std::vector<Entity*>& entities, const double& time) {}
   virtual bool hasExpired() { return false; } // only fragment class will override
   virtual void defunctChance(int i) {}             // only satellite will override

protected:
   Position position;
   Velocity velocity;
   Angle angle;
   bool isBroken;
   double radius;
   Thrust thrust;
   int fragmentCount;

   // for satellite defunct
   bool isDefunct;
   int chanceDefunct;
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
   EntityDerived(const Entity& e) {}

   virtual void rotate(double delta)           {assert(false);}
   virtual void draw(ogstream& gout)           {assert(false);}
   virtual void impact(std::vector<Entity*> &entities)   { isBroken = true; }
};

