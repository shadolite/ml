/***********************************************************************
 * Header File:
 *    Lander: 
 * Author:
 *    Amy Chambers
 * Summary:
 *    Contains class definition for Lander.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "velocity.h"
#include "point.h"
/*********************************************
 * LANDER
 * Moon Lander.
 *********************************************/
class Lander
{
private:
   Point point;
   Velocity velocity;
   bool alive;
   bool landed;
   int fuel;
   bool thrust;
   float gravity;
   
public:
   //constructors
   Lander() : velocity(0.0, 0.0), alive(true), landed(false),
      fuel(20), thrust(true) {}
   
   //getters
   Point getPoint() const;
   Velocity getVelocity() const;
   bool isAlive();
   bool isLanded();
   int getFuel();
   bool canThrust();
   
   //setters
   void setLanded(bool);
   void setAlive(bool);
   void setFuel(int);

   void applyGravity(float);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();

   void advance();
   void draw();
};

#endif
