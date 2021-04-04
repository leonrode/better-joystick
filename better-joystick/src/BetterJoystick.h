/*
Title: Better Joystick header file
Author: Leon Rode
License: GNU GPLv3
URL: https://github.com/lionrocker/better-joystick
*/

#ifndef BETTERJOYSTICK_H
#define BETTERJOYSTICK_H

#include "Arduino.h"

#define UPPER_RES_BOUND 1023 // 2^10 - 1, highest value possible from the joystick's resolution
#define LOWER_RES_BOUND 0
#define CENTER_DETECT_RADIUS 30

enum DIRECTION {
      UP,
      RIGHT,
      DOWN,
      LEFT,
      CENTER
};

class Joystick {

  public:

    /*
      Constructor [DEFAULT]

      Sets pinMode of d_swPin to be INPUT_PULLUP.
      Others are input by default.

      a_xPin: analog pin representing joystick's x voltage
      a_yPin: analog pin representing joystick's y voltage
      d_swPin: digital pin representing joystick's switch voltage
    */
    Joystick(const int a_xPin, const int a_yPin, const int d_swPin);

    /*
    Method - integer

    Returns:
      raw X value as read by analogRead()
    */
    int x();

    /*
    Method - integer
    
    Returns:
      X value of joystick after mapping raw value (initally between 0 and 1023)
      with the lower and upper bounds

    Parameters:
      lowerBound: lower bound of mapping
      upperBound: upper bound of mapping
    
    Note: map to a 2^n range for best results
    */
    int x(const int lowerBound, const int upperBound);
    
    /*
    Method - integer

    Returns:
      raw Y value as read by analogRead()
    */
    int y();

    /*
    Method - integer
    
    Returns:
      Y value of joystick after mapping raw value (initally between 0 and 1023)
      with the lower and upper bounds

    Parameters:
      lowerBound: lower bound of mapping
      upperBound: upper bound of mapping

    Note: map to a 2^n range for best results
    */
    int y(const int lowerBound, const int upperBound);

    /*
    Method - integer

    Returns:
      1 if the joystick is pressed 
      0 if the joystick is not pressed
    */
    int isPressed();

    /*
    Method - double

    Returns:
      normalized (0 to 1) length of joystick position relative to center
    */
   double magnitude();
    
  /*
  Method - DIRECTION [enum]

  Returns:
    the direction the joystick is being pushed

  Note: there is a macro defined for the radius of the region where DIRECTION::CENTER is returned
        this can be changed depending on the joystick's physical resting position
  */
  DIRECTION facingDirection();

  private:

    double distance(int x1, int y1, int x2, int y2);
    int xPin;
    int yPin;
    int pressedPin;

};

#endif