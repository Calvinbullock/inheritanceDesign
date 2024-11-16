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

protected:
   int fragmentCount;
};
