/***********************************************************************
 * Header File:
 *    Velocity:
 * Author:
 *    Amy Chambers
 * Summary:
 *    Contains class definition for Velocity.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

/*********************************************
 * VELOCITY
 * Velocity of moon lander.
 *********************************************/
class Velocity
{
private:
   float Dx;
   float Dy;

public:
   //constructors
   Velocity(): Dx(0.0), Dy(0.0) {}
  Velocity(float Dx, float Dy): Dx(0.0), Dy(0.0) {}

   //getters
   float getDx();
   float getDy();

   //setters
   void setDx(float);
   void setDy(float);
};

#endif
