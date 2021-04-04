# better-joystick
A better joystick library to handle Arduino joysticks.

## Introduction

Better Joystick allows the user to interface with the Arduino joystick component. 
It provides simple yet useful functions that make sense for a joystick.

## Installation

Better Joystick can be installed through the Library Manager in the Arduino IDE.

## Usage

A simple `Joystick` object can be created with the relevant pins in the constructor, like this:
```
Joystick joystick(A0, A1, 7);
```

The `Joystick` class contains many methods that can be called in a similar fashion.

### int x()

Retrieves the `x` position of the joystick

```joystick.x()```

### int y()

Retrieves the `y` position of the joystick

```joystick.y()```

### int x(const int lowerBound, const int upperBound);

Retrieves the `x` position after mapping from 0, 1023 to `lowerBound`, `upperBound`.

### int y(const int lowerBound, const int upperBound);

Retrieves the `y` position after mapping from 0, 1023 to `lowerBound`, `upperBound`.

### int isPressed()

Returns `1` if the joystick is pressed and `0` if the joystick is not pressed.

### double magnitude()

Returns a value from 0 to 1 representing the normalized distance from the joystick's position to the center (512, 512).

### DIRECTION facingDirection()

Returns an element from the `DIRECTION` enum depending on the direction the joystick is facing.

The `DIRECTION` enum is defined as follows:

```
enum DIRECTION {
      UP,
      RIGHT,
      DOWN,
      LEFT,
      CENTER
};
```

## License

Better Joystick is licensed under the [**GNU General Public License v3.0**](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Contact

Contact me [here](mailto:leon.rode13@gmail.com) if you have any suggestions or comments.

Thanks for viewing!
