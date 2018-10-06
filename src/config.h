#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define BOARD_FIRMWARE_VERSION        "1.0.1"
#define BOARD_HARDWARE_VERSION        "1.0.0"

#define BOARD_NAME                    "Product Name"        // Name of your product. Should match App Export request info.
#define BOARD_VENDOR                  "Company Name"        // Name of your company. Should match App Export request info.
#define BOARD_TEMPLATE_ID             "TMPL0000"

#define PRODUCT_WIFI_SSID             "Our Product"         // Name of the device, to be displayed during configuration. Should match export request info.
#define BOARD_CONFIG_AP_URL           "our-product.cc"      // Config page will be available in a browser at 'http://our-product.cc/'

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

#define USE_NODE_MCU_BOARD
#define SERIAL_DEBUG
#define BOARD_LED_BUTTON
#define DEBUG(ARG) Serial.print(ARG)
#define DEBUGLN(ARG) Serial.println(ARG)
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
// char auth[] = "";
// digital pins

#endif
