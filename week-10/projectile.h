#pragma once

#include "entity.h"
#include "satelliteShip.h"



class Projectile : public Entity
{

public:
   Projectile() : Entity() {}
   Projectile(Position& pos, Velocity& vel,
      Angle& a, bool isBroke = false)
      : Entity(pos, vel, a, isBroke)
   {
      radius = 1 * position.getZoom();
   }

   virtual void draw(ogstream& gout) { gout.drawProjectile(position); }
   virtual void impact(std::vector<Entity*>& entities) { /*isBroken = true; */ }
   void fire(const Interface* pUI, std::vector<Entity*>& entities, SatelliteShip ship);

protected:


};

// velocity of muzzle and ship adds together
// bullet should come straight out of the ship/

// TODO:
/*
   Create a copy constructor off the ship
   set the position to bigger than the ship.
   put FIRE IN SHIP INPUT

*/