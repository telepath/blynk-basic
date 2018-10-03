#ifndef BLYNK_H
#define BLYNK_H
#include "config.h"
#include <BlynkSimpleEsp8266.h>

/* Comment this out to disable prints and save space */
#ifdef SERIAL_DEBUG
#define APP_DEBUG        // Comment this out to disable debug prints
#define BLYNK_PRINT Serial // Defines the object that is used for printing
// #define BLYNK_DEBUG        // Optional, this enables more detailed prints
#endif

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"

enum pins {
  LED_COLOR,  //vPin 0 - EXAMPLE
              // add more pins here
  PIN_NUM     //last item, number of pins
};

// Params for each pin are stored here and can be accessed via e.g.:
// value = pinParams[pin]->asInt();
BlynkParam *pinParams[PIN_NUM];

#endif
