/***********************************************************************
 * Header File:
 *    Entity class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    TODO:
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "position.h"
#include "uiDraw.h"
#include "velocity.h"
#include "angle.h"


/***********************************************************************
 * Entity
 *    TODO:
 ************************************************************************/
class Entity
{
public:

   // Constructors                                                         // TEMP width TODO:
   Entity() {}
   Entity(Position& pos, Velocity& vel, Angle& a, bool isBroke = false, double w = 10.0)
   {
      position = pos;
      velocity = vel; 
      angle = a;
      isBroken = isBroke;
      width = w;
   }

   // Getters
   Position getPosition() const { return position;      }
   Velocity getVelocity() const { return velocity;      }
   bool     getIsBroken() const { return isBroken; }
   double   getWidth()    const { return width;    }
   Angle    getAngle()    const { return angle;    }

   // Setters
   void setPosition  (const Position& newPos) { position = newPos;      }
   void setVelocity  (const Velocity& newVel) { velocity = newVel;      }
   void setIsBroken  (bool broken)            { isBroken = broken; }
   void setAngle     (const Angle& newAngle)  { angle = newAngle;  }
   void setWidth     (double newWidth)        { width = newWidth;  }

   void orbit(double time, double grav, Acceleration accel);
   virtual void draw(ogstream& gout) = 0;
   virtual void impact() = 0;

protected:
   Position position;
   Velocity velocity;
   Angle angle;
   bool isBroken;
   double width;
};
