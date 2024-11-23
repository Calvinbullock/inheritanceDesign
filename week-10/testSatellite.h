
/***********************************************************************
 * Header File:
 *    TEST Satellite
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/

#pragma once


#include "satellite.h"
#include "unitTest.h"

/*******************************
* TEST ENTITY
********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // input
      input_none();
      input_mainDown();
      input_mainLeft();
      input_mainDiagonal();
      input_clockwise();
      input_counterClockwise();

      report("Satellite");
   }

private:

   /*****************************************************************
 *****************************************************************
 * INPUT
 *****************************************************************
 *****************************************************************/

   /*********************************************
 * name:    INPUT NOTHING
 * input:   v=(0, 0), t=(f, f, f) a=0deg
 * output:  a=(0, -1.0)
 *********************************************/
   void input_none()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = false;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == false);
   }  // teardown

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING DOWN
   * input:   v=(0, 0), t=(f, f, t) a=0deg
   * output:  a=(0, 1.9795404)
   *********************************************/
   void input_mainDown()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 3.141593;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, 3.141593);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, -3.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, -2.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
   }  // teardown

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING LEFT
   * input:   v=(0, 0), t=(f, f, t) a=270deg
   * output:  a=(2.9795404, -1.0)
   *********************************************/
   void input_mainLeft()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = -1.57079;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, -1.57079);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, -3.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, -2.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
   }  // teardown

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING DIAGONAL
   * input:   v=(0, 0), t=(f, f, t) a=30deg
   * output:  a=(-1.4897, 1.580357)
   *********************************************/
   void input_mainDiagonal()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.785398;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, 0.785398);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, 2.12132);
      assertEquals(s.position.y, 2.12132);
      assertEquals(s.velocity.dx, 1.41421);
      assertEquals(s.velocity.dy, 1.41421);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
   }  // teardown

   /*********************************************
   * name:    INPUT COAST CLOCKWISE
   * input:   v=(0, 0), t=(t, f, f) a=0deg
   * output:  a=(0, -1.0)
   *********************************************/
   void input_clockwise()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.0;
      Thrust t;
      t.clockwise = true;
      t.counterClockwise = false;
      t.mainEngine = false;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, 0.1);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(t.clockwise == true);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == false);
   }  // teardown

   /*********************************************
   * name:    INPUT COAST COUNTERCLOCKWISE
   * input:   v=(0, 0), t=(t, f, f) a=.4rad
   * output:  a=(0, -1.0)
   *********************************************/
   void input_counterClockwise()
   {  // setup
      Satellite s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = true;
      t.mainEngine = false;
      double time = 1.0;

      // exercise
      s.input(t, time);

      // verify
      assertEquals(s.angle.radians, 6.18318);
      assertUnit(s.isBroken == false);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == true);
      assertUnit(t.mainEngine == false);
   }  // teardown
};
