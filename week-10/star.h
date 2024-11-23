/***********************************************************************
 * Source File:
 *    Star
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about Star
 ************************************************************************/

#pragma once

#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Star
{
public:
   Star(Position &ptUpperRight) : position(), phase()
   {
      phase = 4 * random(1, 50);
      position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
   }

   void draw(ogstream &gout)
   {
      phase++;
      gout.drawStar(position, phase);
   }

private:
   Position position;
   unsigned char phase;
};
