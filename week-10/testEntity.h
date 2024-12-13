/***********************************************************************
 * Header File:
 *    TEST Entity
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for Entity
 ************************************************************************/

#pragma once

#include "entity.h"
#include "uiInteract.h"
#include "unitTest.h"

class Interface;

/*******************************
* TEST ENTITY
*     A friend class for Entity which contains the Entity unit tests
********************************/
class TestEntity : public UnitTest
{
public:
   void run()
   {
      // constructor
      entityDefaultConstructor();
      entityConstructor();

      // getters
      getPosition();
      getVelocity();
      getIsBroken();
      getRadius();
      getAngle();

      // setters
      setPosition();
      setVelocity();
      setIsBroken();
      setRadius();
      setAngle();

      //orbit
      orbit_zero();
      orbit_noTime();
      orbit_noAcceleration();
      orbit_noVelocity();
      orbit_all();

      // input
      input_none();

      report("Entity");
   }

private:
   /*********************************************
   * name:    ENTITY DEFAULT CONSTRUCTOR
   * input:   None
   * output:  p=(0.0, 0.0) v=(0.0, 0.0)
   *********************************************/
   void entityDefaultConstructor()
   {
      // setup

      // exercise
      EntityDerived e = EntityDerived();

      // verify
      assertEquals(e.angle.radians, 0.0);
      assertEquals(e.position.x, 0.0);
      assertEquals(e.position.y, 0.0);
      assertEquals(e.velocity.dx, 0.0);
      assertEquals(e.velocity.dy, 0.0);
      assertEquals(e.radius, 2.0);    // default value: 2.0
      assertEquals(e.fragmentCount, 0); // default value: 0
      assertUnit(e.isBroken == false);
      assertUnit(e.thrust.clockwise == false);
      assertUnit(e.thrust.counterClockwise == false);
      assertUnit(e.thrust.mainEngine == false);
   } // teardown

   /*********************************************
   * name:    ENTITY DEFAULT CONSTRUCTOR
   * input:   pos(0.0, 0.0), vel(0.0, 0.1), a.radians = 0.0
   * output:  p=(0.0, 0.0) v=(0.0, 0.0)
   *********************************************/
   void entityConstructor()
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Angle a;
      a.radians = 0;

      // exercise
      EntityDerived e = EntityDerived(pos, vel, a);

      // verify
      assertEquals(e.angle.radians, 0.0);
      assertEquals(e.position.x, 0.0);
      assertEquals(e.position.y, 0.0);
      assertEquals(e.velocity.dx, 0.0);
      assertEquals(e.velocity.dy, 0.0);
      assertEquals(e.radius, 2.0);    // default value: 2.0
      assertEquals(e.fragmentCount, 0); // default value: 0
      assertUnit(e.isBroken == false);
      assertUnit(e.thrust.clockwise == false);
      assertUnit(e.thrust.counterClockwise == false);
      assertUnit(e.thrust.mainEngine == false);
   } // teardown

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

      EntityDerived entity;
      entity.isBroken = false;
      entity.position.x = 0.0;
      entity.position.y = 0.0;
      entity.velocity.dx = 0.0;
      entity.velocity.dy = 0.0;
      entity.angle.radians = 0.0;
      entity.thrust.clockwise = false;
      entity.thrust.counterClockwise = false;
      entity.thrust.mainEngine = false;

      double time = 1.0;

      std::vector<Entity*> entities = {};

      // exercise
      entity.input(&ui, entities, time);

      // verify
      assertEquals(entity.angle.radians, 0.0);
      assertEquals(entity.position.x, 0.0);
      assertEquals(entity.position.y, 0.0);
      assertEquals(entity.velocity.dx, 0.0);
      assertEquals(entity.velocity.dy, 0.0);
      assertUnit(entities.size() == 0);
      assertUnit(entity.isBroken == false);
      assertUnit(entity.thrust.clockwise == false);
      assertUnit(entity.thrust.counterClockwise == false);
      assertUnit(entity.thrust.mainEngine == false);
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
    * name:  GET POSITION
    * input:  entity with position (10.0, 20.0)
    * output: position (10.0, 20.0)
    *********************************************/
   void getPosition()
   {
      // Setup
      Position position;
      position.x = 10.0;
      position.y = 20.0;
      Velocity vel;
      vel.dx = 3.0;
      vel.dy = 4.0;
      Angle angle(45.0);
      EntityDerived entity;
      entity.position = position;
      entity.velocity = vel;
      entity.angle = angle;

      // Exercise
      Position result = entity.getPosition();

      // Verify
      assertEquals(result.x, 10.0);
      assertEquals(result.y, 20.0);
   }

   /*********************************************
    * name:  GET VELOCITY
    * input:  entity with velocity (3.0, 4.0)
    * output: velocity (3.0, 4.0)
    *********************************************/
   void getVelocity()
   {
      // Setup
      Position position;
      position.x = 10.0;
      position.y = 20.0;
      Velocity vel;
      vel.dx = 3.0;
      vel.dy = 4.0;
      Angle angle(45.0);
      EntityDerived entity;
      entity.position = position;
      entity.velocity = vel;
      entity.angle = angle;

      // Exercise
      Velocity result = entity.getVelocity();

      // Verify
      assertEquals(result.dx, 3.0);
      assertEquals(result.dy, 4.0);
   }

   /*********************************************
    * name:  GET IS BROKEN
    * input:  entity with isBroken = true
    * output: isBroken = true
    *********************************************/
   void getIsBroken()
   {
      // Setup
      EntityDerived entity;
      entity.isBroken = true;

      // Exercise
      bool result = entity.getIsBroken();

      // Verify
      assertEquals(result, true);
   }

   /*********************************************
    * name:  GET Radius
    * input:  entity with width = 10.0
    * output: width = 10.0
    *********************************************/
   void getRadius()
   {
      // Setup
      Position position;
      position.x = 10.0;
      position.y = 20.0;
      Velocity vel;
      vel.dx = 3.0;
      vel.dy = 4.0;
      Angle angle(45.0);

      EntityDerived entity;
      entity.position = position;
      entity.velocity = vel;
      entity.angle = angle;
      entity.radius = 10.0;

      // Exercise
      double result = entity.getRadius();

      // Verify
      assertEquals(result, 10.0);
   }

   /*********************************************
    * name:  GET ANGLE
    * input:  entity with angle = 45.0 degrees
    * output: angle = 0.785398 degrees
    *********************************************/
   void getAngle()
   {
      // Setup
      Position position;
      position.x = 10.0;
      position.y = 20.0;
      Velocity vel;
      vel.dx = 3.0;
      vel.dy = 4.0;
      Angle angle(45.0);

      EntityDerived entity;
      entity.position = position;
      entity.velocity = vel;
      entity.angle = angle;

      // Exercise
      Angle result = entity.getAngle();

      // Verify
      assertEquals(result.radians, 0.785398);
   }

   /*********************************************
    * name:  SET POSITION
    * input:  entity with initial position, new position (50.0, 60.0)
    * output: entity with position (50.0, 60.0)
    *********************************************/
   void setPosition()
   {
      // Setup
      EntityDerived entity;
      Position newPos;
      newPos.x = 50.0;
      newPos.y = 60.0;

      // Exercise
      entity.setPosition(newPos);

      // Verify
      assertEquals(entity.position.x, 50.0);
      assertEquals(entity.position.y, 60.0);
   }

   /*********************************************
    * name:  SET VELOCITY
    * input:  entity with initial velocity, new velocity (10.0, 15.0)
    * output: entity with velocity (10.0, 15.0)
   *********************************************/
   void setVelocity()
   {
      // Setup
      EntityDerived entity;
      Velocity newVel;
      newVel.dx = 10.0;
      newVel.dy = 15.0;

      // Exercise
      entity.setVelocity(newVel);

      // Verify
      assertEquals(entity.velocity.dx, 10.0);
      assertEquals(entity.velocity.dy, 15.0);
   }

   /*********************************************
    * name:  SET IS BROKEN
    * input:  entity with initial isBroken state
    * output: entity with isBroken = true
    *********************************************/
   void setIsBroken()
   {
      // Setup
      EntityDerived entity;

      // Exercise
      entity.setIsBroken(true);

      // Verify
      assertUnit(entity.isBroken);
   }
   /*********************************************
    * name:  SET Radius
    * input:  entity with initial width
    * output: entity with width = 2
    *********************************************/
   void setRadius()
   {
      // Setup
      EntityDerived entity;
      entity.radius = 99.0;

      // Exercise
      entity.setRadius(20.0);

      // Verify
      assertEquals(entity.radius, 20.0);
   }

   /*********************************************
    * name:  SET ANGLE
    * input:  entity with initial angle, new angle = 90.0 degrees
    * output: entity with angle = 1.5708 radians
    *********************************************/
   void setAngle()
   {
      // Setup
      EntityDerived entity;
      Angle newAngle(90.0);

      // Exercise
      entity.setAngle(newAngle);

      // Verify
      assertEquals(entity.angle.radians, 1.5708);
   }

   /*********************************************
    * name:    ORBIT WHILE NOT MOVING
    * input:   position=(100, 200), v=(0, 0), a=(0,0) t=1.0
    * output:  position=(100, 200), v=(0, 0)
    *********************************************/
   void orbit_zero()
   {  // setup
      EntityDerived entity;
      entity.position.x = 100.0;
      entity.position.y = 200.0;
      entity.velocity.dx = 0.0;
      entity.velocity.dy = 0.0;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      double t = 1.0;

      // exercise
      entity.orbit(t, a);

      // verify
      assertEquals(entity.position.x, 100.0);     // did not move
      assertEquals(entity.position.y, 200.0);     // did not move
      assertEquals(entity.velocity.dx, 0.0); // same as before
      assertEquals(entity.velocity.dy, 0.0); // same as before
      assertEquals(a.ddx, 0.0);         // no acceleration
      assertEquals(a.ddy, 0.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ORBIT WITH ZERO TIME
    * input:   position=(100, 200), v=(30, 40), a=(5, 6) t=0.0
    * output:  position=(100, 200), v=(30, 40)
    *********************************************/
   void orbit_noTime()
   {  // setup
      EntityDerived entity;
      entity.position.x = 100.0;
      entity.position.y = 200.0;
      entity.velocity.dx = 30.0;
      entity.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 0.0;                   // zero time!

      // exercise
      entity.orbit(t, a);

      // verify
      assertEquals(entity.position.x, 100.0);     // did not move
      assertEquals(entity.position.y, 200.0);
      assertEquals(entity.velocity.dx, 30.0);// no change in velocity
      assertEquals(entity.velocity.dy, 40.0);
      assertEquals(a.ddx, 5.0);         // no change in acceleration
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 0.0);
   }  // teardown

   /*********************************************
    * name:    ORBIT WITH VELOCITY NO ACCELERATION
    * input:   position=(100, 200), v=(30, 40), a=(0, 0) t=2.0
    * output:  position=(160, 280), v=(30, 40)
    *********************************************/
   void orbit_noAcceleration()
   {  // setup
      EntityDerived entity;
      entity.position.x = 100.0;
      entity.position.y = 200.0;
      entity.velocity.dx = 30.0;
      entity.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      double t = 2.0;

      // exercise
      entity.orbit(t, a);

      // verify
      assertEquals(entity.position.x, 160.0);     // 100(x) + 30(dx)*2 + .5*0(ddx)*2*2
      assertEquals(entity.position.y, 280.0);     // 200(y) + 40(dy)*2 + .5*0(ddy)*2*2
      assertEquals(entity.velocity.dx, 30.0);// no change in velocity
      assertEquals(entity.velocity.dy, 40.0);
      assertEquals(a.ddx, 0.0);         // acceleration  unchanged
      assertEquals(a.ddy, 0.0);
      assertEquals(t, 2.0);
   }  // teardown

   /*********************************************
    * name:    ORBIT WITH NO VELOCITY BUT ACCELERATION
    * input:   position=(100, 200), v=(0, 0), a=(5, 6) t=2.0
    * output:  position=(110, 212), v=(10, 12)
    *********************************************/
   void orbit_noVelocity()
   {  // setup
      EntityDerived entity;
      entity.position.x = 100.0;
      entity.position.y = 200.0;
      entity.velocity.dx = 0.0;
      entity.velocity.dy = 0.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 2.0;

      // exercise
      entity.orbit(t, a);

      // verify
      assertEquals(entity.position.x, 110.0); // 100 + 0*2 + .5*5*4
      assertEquals(entity.position.y, 212.0); // 200 + 0*2 + .5*6*4
      assertEquals(entity.velocity.dx, 10.0);  // 0 + 5*2 = 10.0
      assertEquals(entity.velocity.dy, 12.0);  // 0 + 6*2 = 12.0
      assertEquals(a.ddx, 5.0);
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 2.0);
   }  // teardown

   /*********************************************
    * name:    ORBIT WITH VELOCITY, ACCELERATION, AND TIME
    * input:   position=(100, 200), v=(30, 40), a=(5, 6) t=2.0
    * output:  position=(170, 292), v=(40, 52)
    *********************************************/
   void orbit_all()
   {  // setup
      EntityDerived entity;
      entity.position.x = 100.0;
      entity.position.y = 200.0;
      entity.velocity.dx = 30.0;
      entity.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 2.0;

      // exercise
      entity.orbit(t, a);

      // verify
      assertEquals(entity.position.x, 170.0); // 100 + 30*2 + .5*5*4 = 100 + 60 + 10
      assertEquals(entity.position.y, 292.0); // 200 + 40*2 + .5*6*4 = 200 + 80 + 12
      assertEquals(entity.velocity.dx, 40.0);  // 30 + 5*2
      assertEquals(entity.velocity.dy, 52.0);  // 40 + 6*2
      assertEquals(a.ddx, 5.0);
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 2.0);
   }  // teardown




};

