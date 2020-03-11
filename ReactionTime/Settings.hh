/*
    -----------------
    Various settings.
    -----------------
*/

#pragma once

/*----------
   Sonar
----------*/

// How many pings, for a median reading (> 1)
// Lower count equals more probes per second.
// Higher count equals less false positives.
#define SONAR_PING_READY_STATE_MEDIAN_COUNT  5

/*-------------
   Gameplay
-------------*/

// How long the player has to hold their hand in front
// of the sonar, to start a game? In seconds.
#define GAMEPLAY_HOLD_HAND_TO_START_S        5

// The maximum distance of the hand from the sonar
#define GAMEPLAY_HAND_MAX_DISTANCE_CM        10

// Minimum number of seconds before the signal is set
#define GAMEPLAY_SIGNAL_TRIG_MIN_S           3

// Maximum number of seconds before the signal is set
#define GAMEPLAY_SIGNAL_TRIG_MAX_S           10

/*-------------
     Lights
-------------*/

// 0 (min) - 255 (max)
#define LIGHTS_BRIGHTNESS                    50

// In 'started' game mode, how often to change the
// lights.
#define LIGHTS_GAME_STARTED_CHANGE_EVERY_MS  500

/*-------------
     Display
-------------*/

// Is the display flipped, 180 degrees?
#define DISPLAY_FLIPPED                      false