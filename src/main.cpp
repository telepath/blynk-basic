#include "blynk.h"
#include <Arduino.h>
#include <Wire.h>
#include <Automaton.h>
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

  DEBUGLN(F("Initialize pinParams"));
  for (size_t i = 0; i < PIN_NUM; i++) {
    BlynkParam param = BlynkParamAllocated(sizeof(BLYNK_PARAM_PLACEHOLDER_64));
    pinParams[i] = &param;
  }

  DEBUGLN(F("Start Blynk Provisioning"));
  BlynkProvisioning.begin();

  DEBUGLN(F("Setup done."));
  DEBUGLN(F(""));
}

void loop() {
  BlynkProvisioning.run();
  automaton.run();
}

void vWrite(int pin, int value) {
  DEBUG(F("Write "));
  DEBUG(value);
  DEBUG(F(" to pin "));
  DEBUG(pin);
  DEBUGLN(F(""));
  Blynk.virtualWrite(pin, value);
}

void vWrite(int pin, double value) {
  DEBUG(F("Write "));
  DEBUG(value);
  DEBUG(F(" to pin "));
  DEBUG(pin);
  DEBUGLN(F(""));
  Blynk.virtualWrite(pin, value);
}

void vWrite(int pin, BlynkParam &param) {
  DEBUG(F("Write "));
  DEBUG(param.asString());
  DEBUG(F(" to pin "));
  DEBUG(pin);
  DEBUGLN(F(""));
  Blynk.virtualWrite(pin, param);
}

BLYNK_READ_DEFAULT()
{
  int pin = request.pin;      // Which pin is handled?
  int value = 0;
  // if (pin==tankFullVPin) {
  //   value = tankFull;
  // }
  if (!pinParams[pin]->isEmpty()) {
    vWrite(pin, (BlynkParam&)pinParams[pin]);
  }
}

BLYNK_WRITE_DEFAULT()
{
  int pin = request.pin;      // Which pin is handled?
  DEBUG(F("Received "));
  DEBUG(param.asString());
  DEBUG(F(" on pin "));
  DEBUG(pin);
  DEBUGLN(F(""));

  *pinParams[pin] = BlynkParam(param);
}

void blynk_writeConfig() {
  for (size_t i = 0; i < PIN_NUM; i++) {
    if (!pinParams[i]->isEmpty()) {
      vWrite(i, (BlynkParam&)pinParams[i]);
    }
  }
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
    blynk_writeConfig();
}
