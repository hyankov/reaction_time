/*
    -------------------------------------------------------------
    Pin layout. Set pins below the pins according to your wiring.
    -------------------------------------------------------------
*/

#pragma once

// Misc
#define PIN_UNUSED_ANALOG       0

// Lights
#define PIN_LIGHTS_LATCH        11
#define PIN_LIGHTS_CLOCK        9
#define PIN_LIGHTS_DATA         12
#define PIN_LIGHTS_BRIGHTNESS   10

/*
    74HC595 diagram:

    -Q1  v  VCC-
    -Q2     Q0-
    -Q3     DS-
    -Q4     OE-
    -Q5     ST_CP-
    -Q6     SH_CP-
    -Q7     MR-
    -GND    Q7-
*/
#define _74HC595_Q0 (1 << 0)
#define _74HC595_Q1 (1 << 1)
#define _74HC595_Q2 (1 << 2)
#define _74HC595_Q3 (1 << 3)
#define _74HC595_Q4 (1 << 4)
#define _74HC595_Q5 (1 << 5)
#define _74HC595_Q6 (1 << 6)
#define _74HC595_Q7 (1 << 7)
#define LED1_R _74HC595_Q1
#define LED1_G _74HC595_Q2
#define LED1_B _74HC595_Q3
#define LED2_R _74HC595_Q6
#define LED2_G _74HC595_Q5
#define LED2_B _74HC595_Q4

// Sonar
#define PIN_SONAR_TRIG          3
#define PIN_SONAR_ECHO          4