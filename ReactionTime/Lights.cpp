/*
    -------------------------------------
    The module which controls the lights.
    -------------------------------------
*/

// 2nd party includes
#include "Arduino.h"

// 1st party includes
#include "Pins.hh"     // Pin layout. Set pins according to your wiring
#include "Settings.hh" // Include settings
#include "World.hh"    // The world

/* -----------------------
    Private methods
----------------------- */

byte _rgbLed1[] = { LED1_R, LED1_G, LED1_B};
byte _rgbLed2[] = { LED2_R, LED2_G, LED2_B};
unsigned long _lightsLastChangedAt = 0;
bool _isRandomColorSet = false;

// Lights up the leds
// - leds: the bit mask
void _lightLeds(byte leds)
{
    digitalWrite(PIN_LIGHTS_LATCH, LOW);
    shiftOut(PIN_LIGHTS_DATA, PIN_LIGHTS_CLOCK, MSBFIRST, leds);
    digitalWrite(PIN_LIGHTS_LATCH, HIGH);
}

/* -----------------------
    Public methods
----------------------- */

void setupLights()
{
    pinMode(PIN_LIGHTS_LATCH, OUTPUT);
    pinMode(PIN_LIGHTS_DATA, OUTPUT);
    pinMode(PIN_LIGHTS_CLOCK, OUTPUT);
    pinMode(PIN_LIGHTS_BRIGHTNESS, OUTPUT);
    analogWrite(PIN_LIGHTS_BRIGHTNESS, 255 - LIGHTS_BRIGHTNESS);
}

void loopLights()
{
    unsigned long now = millis();

    if (world.gameState == GAME_STATE::NOT_STARTED)
    {
        // Game not started - no lights
        _isRandomColorSet = false;
        _lightLeds(0);
    }
    else if (world.gameState == GAME_STATE::STARTED)
    {
        _isRandomColorSet = false;
        if (!_lightsLastChangedAt || now >= _lightsLastChangedAt + LIGHTS_GAME_STARTED_CHANGE_EVERY_MS)
        {
            // Time to change the lights
            // Ensure different colors for the two LEDs
            byte randLed1 = random(0, 3);
            byte randLed2 = random(0, 3);
            while (randLed2 == randLed1) randLed2 = random(0, 3);

            _lightLeds(_rgbLed1[randLed1] | _rgbLed2[randLed2]);
            _lightsLastChangedAt = now;
        }
    }
    else if (world.gameState == GAME_STATE::SETOFF)
    {
        if (!_isRandomColorSet)
        {
            // Set same color for both LEDs
            byte randLed = random(0, 3);
            _lightLeds(_rgbLed1[randLed] | _rgbLed2[randLed]);
            _isRandomColorSet = true;
        }
    }
}