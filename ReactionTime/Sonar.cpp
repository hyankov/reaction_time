/*
    -------------------------------------------------------------------
    The module which controls the hand detection in front of the sonar.
    -------------------------------------------------------------------

    See https://forum.arduino.cc/index.php?topic=106043.0
    See https://playground.arduino.cc/Code/NewPing
*/

// 2nd party includes
#include "Arduino.h"

// 1st party includes
#include "Pins.hh"      // Pin layout. Set pins according to your wiring
#include "Settings.hh"  // Include settings
#include "World.hh"     // The world

// 3rd party includes
#include <NewPing.h>

/* -----------------------
    Private methods
----------------------- */

const unsigned int _sonarTimeout = 30;
unsigned long _nextPingAt;
NewPing _sonar(PIN_SONAR_TRIG, PIN_SONAR_ECHO, GAMEPLAY_HAND_MAX_DISTANCE_CM);

/* -----------------------
    Public methods
----------------------- */

void setupSonar()
{
    _nextPingAt = 0;
    world.isHandInFront = false;
}

void loopSonar()
{
    // Is it time to ping?
    if (world.now >= _nextPingAt)
    {
        if (world.gameState == GAME_STATE::NOT_STARTED)
        {
            // When to ping again
            _nextPingAt = world.now + (SONAR_PING_READY_STATE_MEDIAN_COUNT * _sonarTimeout);

            // With filtering
            world.isHandInFront = NewPing::convert_cm(_sonar.ping_median(SONAR_PING_READY_STATE_MEDIAN_COUNT)) != NO_ECHO;
        }
        else
        {
            // When to ping again
            _nextPingAt = world.now + _sonarTimeout;

            // Single ping
            world.isHandInFront = _sonar.ping_cm() != NO_ECHO;
        }
    }
}