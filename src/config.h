#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>

#define USE_NODE_MCU_BOARD
#define SERIAL_DEBUG        //Comment this out to disable Serial outputs
#define BOARD_LED_BUTTON

#include "Settings.h"

/* Comment this out to disable prints and save space */
#ifdef SERIAL_DEBUG
  #define APP_DEBUG        // Comment this out to disable debug prints
  #define BLYNK_PRINT terminal // Print debug outputs to terminal widget
  // #define BLYNK_PRINT Serial // Print debug outputs to Serial port
  // #define BLYNK_DEBUG        // Optional, this enables more detailed prints
  #define DEBUG(ARG) terminal.print(ARG)
  #define DEBUGLN(ARG) terminal.println(ARG)
  // #define DEBUG(ARG) Serial.print(ARG)
  // #define DEBUGLN(ARG) Serial.println(ARG)
#else
  #define DEBUG
  #define DEBUGLN
#endif

enum pins {
  TERMINAL,       //vPin 0
  PIN_NUM         //last item, number of pins
};

WidgetTerminal terminal(TERMINAL);  // Comment this out if you won't use the terminal widget

// digital pins

#endif
