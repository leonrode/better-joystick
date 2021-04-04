/*
Title: Better Joystick source file
Author: Leon Rode
License: GNU GPLv3
URL: https://github.com/lionrocker/better-joystick
*/

#include "BetterJoystick.h"

Joystick::Joystick(const int a_xPin, const int a_yPin, const int d_swPin) : xPin(a_xPin), yPin(a_yPin), pressedPin(d_swPin) {
  pinMode(pressedPin, INPUT_PULLUP);
}

/* PRIVATE */
double Joystick::distance(int x1, int y1, int x2, int y2) {
  const int scaleDownFactor = 10;

  // dividing by a factor of 10 to stay within integer value range (0 to 32,767)
  // at the cost of one decimal place
  x1 /= scaleDownFactor;
  y1 /= scaleDownFactor;
  x2 /= scaleDownFactor;
  y2 /= scaleDownFactor;

  return (sqrt(sq(x2 - x1) + sq(y2 - y1))) * scaleDownFactor;
}

int Joystick::x() {
  const int x = analogRead(xPin);
  return x;
}

int Joystick::y() {
  const int y = analogRead(yPin);
  return y;
}

int Joystick::x(int lowerBound, int upperBound) {
  const int x = analogRead(xPin); 
  const int mapped = map(x, LOWER_RES_BOUND, UPPER_RES_BOUND, lowerBound, upperBound);
  return mapped;
}

int Joystick::y(int lowerBound, int upperBound) {
  const int y = analogRead(yPin); 
  const int mapped = map(y, LOWER_RES_BOUND, UPPER_RES_BOUND, lowerBound, upperBound);
  return mapped;
}

int Joystick::isPressed() {
  const int pressed = digitalRead(pressedPin);

  // 0 is returned when the joystick is pressed, so the value is flipped to be logical
  return !pressed;
}

double Joystick::magnitude() {
  const int x = analogRead(xPin);
  const int y = analogRead(yPin);
  
  const double dist = distance(x, y, UPPER_RES_BOUND / 2, UPPER_RES_BOUND / 2);

  const double normalized = dist / UPPER_RES_BOUND;

  return normalized;
}

DIRECTION Joystick::facingDirection() {
  const double x = analogRead(xPin);
  const double y = analogRead(yPin);

  const double distanceFromCenter = distance(x, y, UPPER_RES_BOUND / 2, UPPER_RES_BOUND / 2);
  
  if (distanceFromCenter > CENTER_DETECT_RADIUS) {
    if (y <= x && y <= -x + UPPER_RES_BOUND) {
      return DIRECTION::UP;
    } else if (y > x && y > -x + UPPER_RES_BOUND) {
      return DIRECTION::DOWN;
    } else if (y > x && y < -x + UPPER_RES_BOUND) {
      return DIRECTION::LEFT;
    } else {
      return DIRECTION::RIGHT;
    }
  } else {
    return DIRECTION::CENTER;
  }
}