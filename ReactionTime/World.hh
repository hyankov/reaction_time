/*
    -------------------
    World property bag.
    -------------------
*/

#pragma once

// 2nd party includes
#include "Arduino.h"

// The possible game states
enum GAME_STATE
{
    // Player must hover hand over sensor
    NOT_STARTED,

    // The game is started, player has to react on signal
    STARTED,

    // Player must move hand away from sensor
    SETOFF
};

// Property bag, describing the world state
struct World
{
    /* -----------------------
        Private methods
    ----------------------- */

    // Is the last result bad
    bool _lastResultIsBad = false;

    // The best result
    unsigned int _resultBestMs = 0;

    // The last result
    unsigned int _resultLastMs = 0;

    /* -----------------------
        Public methods
    ----------------------- */

    // The game state
    enum GAME_STATE gameState = GAME_STATE::NOT_STARTED;

    // Whether the player hand is in front of the sensor
    bool isHandInFront = false;

    // When does the game start (time)
    unsigned int gameStartsAt = 0;

    // Gets the best result, as string
    String getBestResult()
    {
        return _resultBestMs ? String(_resultBestMs) + " ms" : "N/A";
    }

    // Gets the last result, as string
    String getLastResult()
    {
        if (_lastResultIsBad)
        {
            return "bad try";
        }
        else
        {
            return _resultLastMs ? String(_resultLastMs) + " ms" : "N/A";
        }
    }

    // Whether there is a best result recorded yet
    bool hasBestResult()
    {
        return _resultBestMs > 0;
    }

    // Updates the results.
    // - newResultLastMs: the newest result.
    void setLastResult(unsigned int newResultLastMs)
    {
        _lastResultIsBad = false;
        _resultLastMs = newResultLastMs;
        _resultBestMs = hasBestResult() ? min(_resultBestMs, _resultLastMs) : _resultLastMs;
    }

    // Mark the last result as bad.
    void setLastResultAsBad()
    {
        _lastResultIsBad = true;
        _resultLastMs = 0;
    }
};

// An instance of the World property bag
extern struct World world;