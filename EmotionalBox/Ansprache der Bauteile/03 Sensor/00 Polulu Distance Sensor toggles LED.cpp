/*
Belegungsplan:
2:      Toggle
4:      Button
14:     LED
9:     Distance Sensor
*/

#include "FastLED.h"
#include <Arduino.h>
#include <Bounce2.h>

/*
Ein Kabel (z.B. rot) an PIN 2 stecken. Das andere (weiß) muss auf Ground (PIN G) gesteckt werden.
Nur so funktioniert es.
*/

const int sensorPin = 9;
const int temporalThreshold = 100; // wie lange wird gebraucht bis wir eine state Änderung als einen neuen State akzeptieren

volatile unsigned long interruptionMillis;
unsigned long currentMillis;
const unsigned long period = 200;

// variables that will change:
volatile byte lastSensorUpdate = 0; // Der Zeitstempel von der letzten Veränderung. Genutzt beim Sensor

volatile int sensorState;
volatile int oldSensorState;
volatile bool handThere;

// Die Methode die im Interrupt aufgerufen wird (countActions) wird davon abgehalten wiederholt aufgerufen zu werden
boolean blocked = false;

// Stuff for my LED
#define LED_TYPE    NEOPIXEL
#define COLOR_ORDER GRB
#define NUM_LEDS    28
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 123
#define FRAMES_PER_SECOND  120

uint8_t hue;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns


void setup() {
  interruptionMillis = 0;

  pinMode(sensorPin, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(sensorPin), sensorInterrupt, CHANGE);

  FastLED.addLeds<NEOPIXEL, 14>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

}

void loop() {
  currentMillis = millis();

  if (currentMillis - interruptionMillis >= period && blocked == true) {
    attachInterrupt(digitalPinToInterrupt(sensorPin), sensorInterrupt, CHANGE);
    interruptionMillis = currentMillis;
    blocked = false;
  }

  if (sensorState != oldSensorState) {
    oldSensorState = sensorState;
    lightUp();
  }
}

void sensorInterrupt() {
  interruptionMillis = millis();
  sensorState = digitalRead(sensorPin);
  blocked = true;
  detachInterrupt(digitalPinToInterrupt(sensorPin));

}

void lightUp(){
  if (sensorState == LOW) { //
    fill_solid( leds, NUM_LEDS, CHSV(160,255,255) );  //set color of pixels - blue
    FastLED.show();  // display the pixels
  }
  if (sensorState == HIGH) { //
    FastLED.clear();
    FastLED.show();  // display the pixels
  }
}


