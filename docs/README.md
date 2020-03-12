- [Game Rules](#game-rules)
- [Setup](#setup)
  - [Components](#components)
  - [Wiring](#wiring)
- [Code](#code)
  - [Main sketch](#main-sketch)
  - [Settings](#settings)
  - [Display](#display)
  - [Gameplay](#gameplay)
  - [Lights](#lights)
  - [Sonar](#sonar)
  - [World](#world)

# Game Rules
The player holds his hand over the sensor for a few seconds and that starts the game. Two RGB (Red, Green, Blue) LEDs start flashing in different colors. At a random time they will stop flashing and will remain lit, with the same color (e.g. both would become Blue). The player has to react as quick as possible and move his hand away from the sensor. The reaction time is recorded. The game is keeping track of the best reaction time so far. If the player moves their hand away from the sensor, before the signal is set off (i.e. before the LEDs stop flashing and remain the same color), that's considered a "bad" attempt.

| Video 1  | Video 2 |
| ------------- | ------------- |
[<img src="https://img.youtube.com/vi/OYXGrj66SCE/0.jpg" alt="Video 1" title="Video 1" width="250" />](https://www.youtube.com/watch?v=OYXGrj66SCE)  | [<img src="https://img.youtube.com/vi/7_lOLILgES0/0.jpg" alt="Video 2" title="Video 2" width="250" />](https://www.youtube.com/watch?v=7_lOLILgES0)

# Setup
## Components
- Ultrasonic sensor HC-SR04
- 220 ohm resistors
- Two RGB LEDs
- [IIC 0.91" OLED Display](https://www.amazon.com/gp/product/B07D9H83R4)
- Some wires
- Breadboard
- Arduino Uno r3


## Wiring
[![Wiring](img/wiring.jpg)](wiring.fzz)
*Click image to download `fzz` file*

# Code
**See [code here](../ReactionTime/)**. All code is implemented as non-blocking, i.e. there are no `delay` calls.

## Main sketch
The main sketch can be found here:
- [ReactionTime.ino](../ReactionTime/ReactionTime.ino)

## Settings
There is two setting files that may need adjustment:
- [Settings](../ReactionTime/Settings.hh) - various settings.
- [Pins layout](../ReactionTime/Pins.hh) - the Arduino pins to be setup in accordance with your own wiring.

## Display
Code responsible for rendering information on the screen:
- [Display](../ReactionTime/Display.cpp)
  
## Gameplay
The gameplay is driven by the code here:
- [Gameplay](../ReactionTime/Gameplay.cpp)
  
## Lights
The lights management is implemented here:
- [Lights](../ReactionTime/Lights.cpp)
  
## Sonar
Detecting the player's hand using the sonar is implemented here:
- [Lights](../ReactionTime/Sonar.cpp)
  
## World
Keeping track of the game 'world' is done here:
- [World](../ReactionTime/World.hh)