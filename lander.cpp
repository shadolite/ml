/***********************************************************************
 * Source File:
 *    Lander: Class definition for lander object
 * Author:
 *    Amy Chambers
 * Summary:
 *    Everythibng needed for manipulation of the lander object.
 ************************************************************************/

#include "lander.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/******************************************
 * getPoint
 * Return current point
 *****************************************/
Point Lander::getPoint() const
{
   return point;
}


/******************************************
 * getVelocity
 * Return current velocity
 *****************************************/
Velocity Lander::getVelocity() const
{
   return velocity;
}

/******************************************
 * isAlive
 * Return alive status
 *****************************************/
bool Lander::isAlive()
{
   return alive;
}

/******************************************
 * isLanded
 * Return landed status
 *****************************************/
bool Lander::isLanded()
{
   return landed;
}

/******************************************
 * getFuel
 * Return remaining fuel
 *****************************************/
int Lander::getFuel()
{
   return fuel;
}

/******************************************
 * canThrust
 * Return thrust capability
 *****************************************/
bool Lander::canThrust()
{
   return thrust;
}

/******************************************
 * setLanded
 * Set landed status
 *****************************************/
void Lander::setLanded(const bool landed)
{
   this->landed = landed;
}

/******************************************
 * setAlive
 * Set alive status
 *****************************************/
void Lander::setAlive(const bool alive)
{
   this->alive = alive;
}

/******************************************
 * setFuel
 * Set remaining amount of fuel
 *****************************************/
void Lander::setFuel(const int fuel)
{
   this->fuel = fuel;
}

/******************************************
 * applyGravity
 * Apply gravity to lander object
 *****************************************/
void Lander::applyGravity(const float gravity)
{
   velocity.setDy(velocity.getDy() - gravity);
}

/******************************************
 * applyThrustLeft
 * Apply left thrust to velocity
 *****************************************/
void Lander::applyThrustLeft()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel--;
      velocity.setDx(velocity.getDx() + 1); //update later!
   };
   
}

/******************************************
 * applyThrustRight
 * Apply right thrust to velocity
 *****************************************/
void Lander::applyThrustRight()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel--;
      velocity.setDx(velocity.getDx() - 1); //update later!
   };   
}

/******************************************
 * applyThrustBottom
 * Apply bottom thrust to velocity
 *****************************************/
void Lander::applyThrustBottom()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel--; //update!!
      velocity.setDy(velocity.getDy() + 1); //update later!
   };
}

/******************************************
 * advance
 * Advance the lander with velocity and gravity
 *****************************************/
void Lander::advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}

/******************************************
 * draw
 * Draw lander on screen
 *****************************************/
void Lander::draw()
{
    drawLander(point);
}
