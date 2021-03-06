#include "blynk.h"
#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "BlynkProvisioning.h"

void setup() {
  Wire.begin();

  //Setup Serial for debugging
  #ifdef SERIAL_DEBUG
  Serial.begin(115200);
  DEBUGLN(F("Setup Serial"));
  #endif

  DEBUGLN(F("Start Blynk Provisioning"));
  BlynkProvisioning.begin();

  DEBUGLN(F("Setup done."));
  DEBUGLN(F(""));
}

void loop() {
  BlynkProvisioning.run();
}

void vWrite(int pin, BlynkParam &param) {
  DEBUG(F("Write "));
  DEBUG(param.asString());
  DEBUG(F(" to pin "));
  DEBUG(pin);
  DEBUGLN(F(""));
  Blynk.virtualWrite(pin, param);
}

void blynk_writeConfig() {
  for (size_t i = 0; i < PIN_NUM; i++) {
    // BlynkParam param = *pinParams[i];
    if (pinParams[i].isEmpty()) {
      DEBUG(F("pinParams["));
      DEBUG(i);
      DEBUGLN(F("] is empty"));
    } else {
      vWrite(i, pinParams[i]);
    }
  }
}

BLYNK_READ_DEFAULT()
{
  int pin = request.pin;      // Which pin is handled?
  if (pin<PIN_NUM) {
    if (pinParams[pin].isEmpty()) {
      DEBUG(F("pinParams["));
      DEBUG(pin);
      DEBUGLN(F("] is empty"));
    } else {
      vWrite(pin, pinParams[pin]);
    }
  } else {
    DEBUG(F("Invalid pin: "));
    DEBUGLN(pin);
  }
}

BLYNK_WRITE_DEFAULT()
{
  int pin = request.pin;      // Which pin is handled?
  DEBUG(F("Received "));
  DEBUG(param.asString());
  DEBUG(F(" on pin "));
  DEBUGLN(pin);

  if (pin<PIN_NUM) {
    pinParams[pin] = param;
  } else {
    DEBUG(F("Invalid pin: "));
    DEBUGLN(pin);
  }

  switch (pin) {
    case LED_COLOR:
    break;
  }
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
    blynk_writeConfig();
}
