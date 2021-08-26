/*
Title: Better Joystick example file
Author: Leon Rode
License: GNU GPLv3
URL: https://github.com/leonrode/better-joystick
*/
#include <BetterJoystick.h>

// Create a joystick object
Joystick joystick(A0, A1, 8); // (X, Y, SWITCH)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // communicate with the joystick
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void directions() {
  // retrieving the direction the joystick is facing
  DIRECTION direction = joystick.facingDirection();

  // checking against directions
  if (direction == DIRECTION::UP) {
    Serial.println("Joystick is facing upwards.");
  } else if (direction == DIRECTION::DOWN) {
    Serial.println("Joystick is facing downwards.");
  } else if (direction == DIRECTION::LEFT) {
    Serial.println("Joystick is facing left.");
  } else if (direction == DIRECTION::RIGHT) {
    Serial.println("Joystick is facing right.");
  } else { // DIRECTION::CENTER
    // the joystick is not being touched
    // note: if any of the above is being printed when the joystick is centered, change the
    // CENTER_DETECT_RADIUS macro to a larger value in the header file
    Serial.println("Joystick is in its resting position.");
  }
}

void retrievePositions() {
  int xPos = joystick.x();
  int yPos = joystick.y();

  int mappedX = joystick.x(0, 255); // maps from the default 0, 1023 to 0, 255
  int mappedY = joystick.y(0, 255);

  int pressed = joystick.isPressed(); // 0: not pressed, 1: pressed
}

void magnitudes() {
  double magnitude = joystick.magnitude();
}
