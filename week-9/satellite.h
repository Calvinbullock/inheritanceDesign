/***********************************************************************
 * Header File:
 *    Satellite class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    TODO:
 ************************************************************************/

#pragma once

#include "entity.h"

/***********************************************************************
 * Entity
 *    TODO:
 ************************************************************************/
class Satellite : public Entity
{
public:

   // Constructors
   Satellite() : Entity() {}

protected:
   int fragmentCount;
};
