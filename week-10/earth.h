/***********************************************************************
 * Source File:
 *    Earth Class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about Earth
 ************************************************************************/
#pragma once

#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Earth
{
public:
   Earth() : position(0.0, 0.0), rotation(0) {}
   Earth(Position positionIn, double rotaionIn) : position(), rotation()
   {
      position = positionIn;
      rotation = rotaionIn;
   }

   void rotate(double delta)
   {
      rotation -= delta; // 2PI / 1800 || full orbit / frames in a min
   }

   void draw(ogstream &gout)
   {
      gout.drawEarth(position, rotation);
   }

private:
   Position position;
   double rotation;
};
