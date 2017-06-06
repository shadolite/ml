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
   Point lPoint;
   Velocity velocity;
   bool alive;
   bool landed;
   int fuel;
   bool thrust;
   float gravity;

   void setGravity(float);
   void setPoint(Point);
   void setVelocity(Velocity);
   void setThrust(bool);
   
public:
   //constructors
   Lander();
   
   Lander(Point lPoint, Velocity velocity, bool alive,
          bool landed, int fuel, bool thrust, float gravity);
   
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
