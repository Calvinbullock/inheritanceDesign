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
      
      // constructors
      constructor_default();
      constructor_nonDefault();

      // input
      input_none();

      input_mainDown();
      input_mainLeft();
      input_mainUp();
      input_mainRight();

      input_mainTopRight();
      input_mainTopLeft();
      input_mainBottomLeft();
      input_mainBottomRight();

      input_clockwise();
      input_counterClockwise();

      input_fire0Degrees();
      input_fire45Degrees();

      
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

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;

   } 

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING DOWN
   * input:   v=(0, 0), t=(f, f, t) a=3.141593rad
   * output:  v=(0.0, -2.0)
   *********************************************/
   void input_mainDown()
   {  
      // setup
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
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }  

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING LEFT
   * input:   v=(0, 0), t=(f, f, t) a=-1.57079rad
   * output:  v=(-2.0, 0.0)
   *********************************************/
   void input_mainLeft()
   {  
      // setup
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
      s.angle.radians = -1.57079;
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, -1.57079);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, -2.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }  

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING UP
   * input:   v=(0, 0), t=(f, f, t) a=0.0rad
   * output:  v=(0.0, 2.0)
   *********************************************/
   void input_mainUp()
   {
      // setup
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
      s.angle.radians = 0.0; 
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 2.0); 
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING RIGHT
   * input:   v=(0, 0), t=(f, f, t) a=1.570796rad
   * output:  v=(2.0, 0.0)
   *********************************************/
   void input_mainRight()
   {
      // setup
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
      s.angle.radians = 1.570796; // Rightward angle in radians (0 degrees)
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 1.570796);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 2.0); // Positive X for rightward thrust
      assertEquals(s.velocity.dy, 0.0); // No change in Y
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }



   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING TOP RIGHT
   * input:   v=(0, 0), t=(f, f, t) a=0.785398rad
   * output:  v=(1.41421, 1.41421)
   *********************************************/
   void input_mainTopRight()
   {  
      // setup
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
      s.angle.radians = 0.785398;
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 0.785398);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 1.41421);
      assertEquals(s.velocity.dy, 1.41421);
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }  

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING TOP LEFT
   * input:   v=(0, 0), t=(f, f, t) a=2.35619rad
   * output:  v=(-1.41421, 1.41421)
   *********************************************/
   void input_mainTopLeft()
   {
      // setup
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
      s.angle.radians = 2.35619; // Top-left angle in radians (135 degrees)
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 2.35619);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 1.41421); 
      assertEquals(s.velocity.dy, -1.41421);  
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING BOTTOM LEFT
   * input:   v=(0, 0), t=(f, f, t) a=3.92699rad
   * output:  v=(-1.41421, -1.41421)
   *********************************************/
   void input_mainBottomLeft()
   {
      // setup
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
      s.angle.radians = 3.92699; // Bottom-left angle in radians (225 degrees)
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 3.92699);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, -1.41421); 
      assertEquals(s.velocity.dy, -1.41421); 
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

   /*********************************************
   * name:    INPUT MAIN ENGINE POINTING BOTTOM RIGHT
   * input:   v=(0, 0), t=(f, f, t) a=5.49779rad
   * output:  v=(1.41421, -1.41421)
   *********************************************/
   void input_mainBottomRight()
   {
      // setup
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
      s.angle.radians = 5.49779; // Bottom-right angle in radians (315 degrees)
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = true;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 5.49779);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, -1.41421);  
      assertEquals(s.velocity.dy, 1.41421); 
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == true);
      assertUnit(ui.isDownPress == 1);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

   /*********************************************
   * name:    INPUT CLOCKWISE
   * input:   v=(0, 0), t=(t, f, f) a=0rad
   * output:  rad=0.1
   *********************************************/
   void input_clockwise()
   { 
      // setup
      Interface ui;
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 1;
      ui.isSpacePress = 0;

      SatelliteShip s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.0;
      s.thrust.clockwise = true;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = false;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 0.1);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == true);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);
      assertUnit(ui.isDownPress == 0);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 1);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }  

   /*********************************************
   * name:    INPUT COUNTERCLOCKWISE
   * input:   v=(0, 0), t=(f, t, f) a=0.0rad
   * output:  rad=6.18318
   *********************************************/
   void input_counterClockwise()
   {  
      // setup
      Interface ui;
      ui.isDownPress = 0;
      ui.isLeftPress = 1;
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
      s.thrust.counterClockwise = true;
      s.thrust.mainEngine = false;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 6.18318);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(entities.size() == 0);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == true);
      assertUnit(s.thrust.mainEngine == false);
      assertUnit(ui.isDownPress == 0);
      assertUnit(ui.isLeftPress == 1);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 0);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }  

   /***************************************************************************
   * name:    INPUT FIRE SHIP AT (0.0, 0.0) - 0 degrees
   * input:   press space, ship - pos(0.0, 0.0), vel(0.0, 0.0)
   * output:  enities.size = 1 , projectile - pos(0.0, 760.0), vel(0.0, 9000.0)
   ***************************************************************************/
   void input_fire0Degrees()
   {
      // setup
      Interface ui;
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 1;

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
      assertUnit(entities.size() == 1);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

      // projectile
      assertEquals(entities[0]->angle.radians, 0.0);
      assertEquals(entities[0]->position.x, 0.0);
      assertEquals(entities[0]->position.y, 760.0); // 19 * 40(meterFromPixel) = 760
      assertEquals(entities[0]->velocity.dx, 0.0);
      assertEquals(entities[0]->velocity.dy, 9000.0);

      assertUnit(ui.isDownPress == 0);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 1);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

   /***************************************************************************
   * name:    INPUT FIRE SHIP at (0,0) - POINTING TOP RIGHT
   * input:   press space, ship - pos(0.0, 0.0), vel(0.0, 0.0)
   * output:  entities.size = 1, projectile - pos(0, 0), vel(6363.96, 6363.96)
   ***************************************************************************/
   void input_fire45Degrees()
   {
      // setup
      Interface ui;
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 1;

      SatelliteShip s;
      s.isBroken = false;
      s.position.x = 0.0;
      s.position.y = 0.0;
      s.velocity.dx = 0.0;
      s.velocity.dy = 0.0;
      s.angle.radians = 0.785398; 
      s.thrust.clockwise = false;
      s.thrust.counterClockwise = false;
      s.thrust.mainEngine = false;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      s.input(&ui, entities, time);

      // verify
      assertEquals(s.angle.radians, 0.785398);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertUnit(entities.size() == 1);
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

      // projectile
      assertEquals(entities[0]->angle.radians, 0.785398);
      assertEqualsTolerance(entities[0]->position.x, 537.4, 0.1);    // 13.435 * 40 = 537.4
      assertEqualsTolerance(entities[0]->position.y, 537.4, 0.1);    // 13.435 * 40 = 537.4
      assertEqualsTolerance(entities[0]->velocity.dx, 6363.96, 0.1); // 9000 * cos(45 degrees)
      assertEqualsTolerance(entities[0]->velocity.dy, 6363.96, 0.1); // 9000 * sin(45 degrees)

      assertUnit(ui.isDownPress == 0);
      assertUnit(ui.isLeftPress == 0);
      assertUnit(ui.isRightPress == 0);
      assertUnit(ui.isSpacePress == 1);

      // teardown
      ui.isDownPress = 0;
      ui.isLeftPress = 0;
      ui.isRightPress = 0;
      ui.isSpacePress = 0;
   }

};