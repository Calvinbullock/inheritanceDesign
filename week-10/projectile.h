/***********************************************************************
 * Header File:
 *    For Projectile class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Projectile
 ************************************************************************/

#pragma once

#include "entity.h"
#include "satelliteShip.h"

class TestSatelliteShip;

/*************************************************************************
 * PROJECTILE
 *************************************************************************/
class Projectile : public Entity
{

   friend TestSatelliteShip;

public:
   Projectile() : Entity() {}
   Projectile(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      radius = 1 * position.getZoom();
      lifespan = 70; // 70 / 30 = 2.33 sec
      activeTime = 0;
   }

   virtual bool hasExpired()
   {
      activeTime++;
      return activeTime == lifespan;
   }
   virtual void draw(ogstream& gout) { gout.drawProjectile(position); }
   virtual void impact(std::vector<Entity*>& entities) { isBroken = true; }

private:
   int lifespan;
   int activeTime;

};

// TODO: clean up this file

// velocity of muzzle and ship adds together
// bullet should come straight out of the ship/

// TODO:
/*
   set the position to bigger than the ship.
*/
