#pragma once


#include "satelliteShip.h"
#include "unitTest.h"

/*******************************
* TEST SatelliteShip
********************************/
class TestSatelliteShip : public UnitTest
{
public:
   void run()
   {
      
      // constructor
      constructor_default();
      constructor_nonDefault();

      // input
      input_none();
      input_mainDown();
      //input_mainLeft();
      //input_mainDiagonal();
      //input_clockwise();
      //input_counterClockwise();
      
      report("SatelliteShip");
   }

private:


   // Constructors

   /*********************************************
   * name:    Default Constructor
   * input:   none
   *********************************************/
   void constructor_default()
   {
      // setup
      
      // exercise
      SatelliteShip s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 5); // default value: 5
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);
      
   } // teardown

   /*********************************************
   * name:    Default Constructor
   * input:   none
   *********************************************/
   void constructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteShip s(p,v,a);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 5); // default value: 5
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown




   /*****************************************************************
   *****************************************************************
   * INPUT
   *****************************************************************
   *****************************************************************/

   /*********************************************
   * name:    INPUT NOTHING
   * input:   v=(0, 0), t=(f, f, f) a=0.0rad
   * output:  p=(0.0, 0.0) v=(0.0, 0.0)
   *********************************************/
   void input_none()
   {  // setup
      Interface ui;
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
      
      SatelliteShip s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.0;
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = false;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);
      assertUnit(ui.isDownPress == 0);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

   }  // teardown

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING DOWN
   * input:   v=(0, 0), t=(f, f, t) a=3.141593rad
   * output:  v=(0.0, -2.0)
   *********************************************/
   void input_mainDown()
   {  // setup
      Interface ui;
      ui.isDownPress = 1;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
      
      SatelliteShip s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 3.141593;
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 3.141593);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, -2.0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);
   }  // teardown
//
//   /*********************************************
//   * name:    INPUT MAIN ENGINE POINTING LEFT
//   * input:   v=(0, 0), t=(f, f, t) a=-1.57079rad
//   * output:  v=(-2.0, 0.0)
//   *********************************************/
//   void input_mainLeft()
//   {  // setup
//      SatelliteShip s;
//      s.isBroken = false;
//      s.position.x = 0.0;
//      s.position.y = 0.0;
//      s.velocity.dx = 0.0;
//      s.velocity.dy = 0.0;
//      s.angle.radians = -1.57079;
//      Thrust t;
//      t.clockwise = false;
//      t.counterClockwise = false;
//      t.mainEngine = true;
//      double time = 1.0;
//
//      // exercise
//      s.input(t, time);
//
//      // verify
//      assertEquals(s.angle.radians, -1.57079);
//      assertUnit(s.isBroken == false);
//      assertEquals(s.velocity.dx, -2.0);
//      assertEquals(s.velocity.dy, 0.0);
//      assertUnit(t.clockwise == false);
//      assertUnit(t.counterClockwise == false);
//      assertUnit(t.mainEngine == true);
//   }  // teardown
//
//   /*********************************************
//   * name:    INPUT MAIN ENGINE POINTING DIAGONAL
//   * input:   v=(0, 0), t=(f, f, t) a=0.785398rad
//   * output:  v=(1.41421, 1.41421)
//   *********************************************/
//   void input_mainDiagonal()
//   {  // setup
//      SatelliteShip s;
//      s.isBroken = false;
//      s.position.x = 0.0;
//      s.position.y = 0.0;
//      s.velocity.dx = 0.0;
//      s.velocity.dy = 0.0;
//      s.angle.radians = 0.785398;
//      Thrust t;
//      t.clockwise = false;
//      t.counterClockwise = false;
//      t.mainEngine = true;
//      double time = 1.0;
//
//      // exercise
//      s.input(t, time);
//
//      // verify
//      assertEquals(s.angle.radians, 0.785398);
//      assertUnit(s.isBroken == false);
//      assertEquals(s.velocity.dx, 1.41421);
//      assertEquals(s.velocity.dy, 1.41421);
//      assertUnit(t.clockwise == false);
//      assertUnit(t.counterClockwise == false);
//      assertUnit(t.mainEngine == true);
//   }  // teardown
//
//   /*********************************************
//   * name:    INPUT CLOCKWISE
//   * input:   v=(0, 0), t=(t, f, f) a=0rad
//   * output:  rad=0.1
//   *********************************************/
//   void input_clockwise()
//   {  // setup
//      SatelliteShip s;
//      s.isBroken = false;
//      s.position.x = 0.0;
//      s.position.y = 0.0;
//      s.velocity.dx = 0.0;
//      s.velocity.dy = 0.0;
//      s.angle.radians = 0.0;
//      Thrust t;
//      t.clockwise = true;
//      t.counterClockwise = false;
//      t.mainEngine = false;
//      double time = 1.0;
//
//      // exercise
//      s.input(t, time);
//
//      // verify
//      assertEquals(s.angle.radians, 0.1);
//      assertUnit(s.isBroken == false);
//      assertEquals(s.position.x, 0.0);
//      assertEquals(s.position.y, 0.0);
//      assertEquals(s.velocity.dx, 0.0);
//      assertEquals(s.velocity.dy, 0.0);
//      assertUnit(t.clockwise == true);
//      assertUnit(t.counterClockwise == false);
//      assertUnit(t.mainEngine == false);
//   }  // teardown
//
//   /*********************************************
//   * name:    INPUT COUNTERCLOCKWISE
//   * input:   v=(0, 0), t=(f, t, f) a=0.0rad
//   * output:  rad=6.18318
//   *********************************************/
//   void input_counterClockwise()
//   {  // setup
//      SatelliteShip s;
//      s.isBroken = false;
//      s.position.x = 0.0;
//      s.position.y = 0.0;
//      s.velocity.dx = 0.0;
//      s.velocity.dy = 0.0;
//      s.angle.radians = 0.0;
//      Thrust t;
//      t.clockwise = false;
//      t.counterClockwise = true;
//      t.mainEngine = false;
//      double time = 1.0;
//
//      // exercise
//      s.input(t, time);
//
//      // verify
//      assertEquals(s.angle.radians, 6.18318);
//      assertUnit(s.isBroken == false);
//      assertEquals(s.position.x, 0.0);
//      assertEquals(s.position.y, 0.0);
//      assertEquals(s.velocity.dx, 0.0);
//      assertEquals(s.velocity.dy, 0.0);
//      assertUnit(t.clockwise == false);
//      assertUnit(t.counterClockwise == true);
//      assertUnit(t.mainEngine == false);
//   }  // teardown

};