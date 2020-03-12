/*
    ---------------------------------------
    The module which controls the gameplay.
    ---------------------------------------
*/

// 2nd party includes
#include "Arduino.h"

// 1st party includes
#include "Pins.hh"      // Pin layout. Set pins according to your wiring
#include "Settings.hh"  // Include settings
#include "World.hh"     // The world

/* -----------------------
    Private methods
----------------------- */

// When was the signal set off
unsigned long _setOffAt = 0;

// Resets the game state to "waiting for hand"
void _resetToWaitForHandState()
{
    _setOffAt = 0;
    world.gameState = GAME_STATE::NOT_STARTED;
    world.gameStartsAt = 0;
}

/* -----------------------
    Public methods
----------------------- */

void setupGameplay()
{
    _resetToWaitForHandState();
}

void loopGameplay()
{
    unsigned long now = millis();

    if (world.gameState == GAME_STATE::NOT_STARTED)
    {
        if (world.isHandInFront)
        {
            if (!world.gameStartsAt)
            {
                // Player just now put his hand in place
                world.gameStartsAt = now + (GAMEPLAY_HOLD_HAND_TO_START_S * 1000);
            }
            else
            {
                // Player is keeping his hand in place, to start the game
                if (now >= world.gameStartsAt)
                {
                    // Player hand was in place long enough to start game
                    // Predetermine when the signal would fire
                    _setOffAt = now + (random(GAMEPLAY_SIGNAL_TRIG_MIN_S, GAMEPLAY_SIGNAL_TRIG_MAX_S + 1) * 1000);

                    // The game is now 'started'
                    world.gameState = GAME_STATE::STARTED;
                }
            }
        }
        else
        {
            // Player moved hand before game started
            _resetToWaitForHandState();
        }
    }
    else if (world.gameState == GAME_STATE::STARTED)
    {
        if (world.isHandInFront)
        {
            if (now >= _setOffAt)
            {
                // Set off the signal
                world.gameState = GAME_STATE::SETOFF;

                // For accuracy, since `now` might be > `_setOffAt`
                _setOffAt = now;
            }
        }
        else
        {
            // Moved hand before the signal was set off!
            world.setLastResultAsBad();
            _resetToWaitForHandState();
        }
    }
    else if (world.gameState == GAME_STATE::SETOFF)
    {
        if (!world.isHandInFront)
        {
            // Player reacted, record the results and reset
            world.setLastResult(now - _setOffAt);
            _resetToWaitForHandState();
        }
    }
}