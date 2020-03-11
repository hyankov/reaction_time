/*
    ---------------------------------------------
    Reaction time game.
    See: https://github.com/hyankov/reaction_time
    ---------------------------------------------
*/

// 1st party includes
#include "Pins.hh"      // Pin layout. Set pins according to your wiring
#include "Settings.hh"  // Include settings
#include "Sonar.hh"     // Sonar handling
#include "Display.hh"   // Display handling
#include "Lights.hh"    // Lights handling
#include "Gameplay.hh"  // Gameplay handling

// Setup and initialize
void setup()
{
    // Random seed
    randomSeed(analogRead(PIN_UNUSED_ANALOG));

    // Setup the sonar
    setupSonar();

    // Setup the gameplay
    setupGameplay();

    // Setup the display
    setupDisplay();

    // Setup the lights
    setupLights();
}

// The main loop, repeating over and over again
void loop()
{
    loopSonar();
    loopGameplay();
    loopDisplay();
    loopLights();
}