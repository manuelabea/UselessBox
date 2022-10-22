#include "FastLED.h"
/*
Ein Kabel (z.B. rot) an PIN 2 stecken. Das andere (weiß) muss auf Ground (PIN G) gesteckt werden.
Nur so funktioniert es.
*/

const int togglePin = 2;
const int buttonPin = 4;
const int temporalThreshold = 100; // wie lange wird gebraucht bis wir eine state Änderung als einen neuen State akzeptieren
volatile int actionCounter = 0; // variable to count which action we're at

// variables that will change:
volatile byte toggleState = LOW; // variable for reading the pushbutton status
volatile byte lastUpdate = 0; // Der Zeitstempel von der letzten Veränderung. Genutzt beim Toggle

volatile int buttonState;

// Die Methode die im Interrupt aufgerufen wird (countActions) wird davon abgehalten wiederholt aufgerufen zu werden
boolean blocked = false;

// Stuff for my LED
#define LED_TYPE    NEOPIXEL
#define COLOR_ORDER GRB
#define NUM_LEDS    28
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 123

uint8_t hue;

void setup() {
  actionCounter = 0;
  pinMode(togglePin,INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(togglePin), countActions, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);

  FastLED.addLeds<NEOPIXEL, 14>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

}

void loop() {

}

void countActions() {
  if (lastUpdate + temporalThreshold < millis() && blocked == false) {
    blocked = true;
    lastUpdate = millis(); // merkt sich wann der Änderungsvorgang gestartet wurde

    delay(50); // wichtig!! Da im Wechsel noch viel passieren kann, warten wir bis sich der State endgültig stabilisiert hat
    toggleState = digitalRead(togglePin); // lesen den Status aus

    if (toggleState == LOW) {
      actionCounter += 1;
      Serial.println("ON ++");
    } else if (toggleState == HIGH) {
      Serial.println("OFF");
    }
    Serial.println("Updated " + String(actionCounter) + " state: " + String(toggleState));

    blocked = false; // Methode wird freigegeben
  }
}

void buttonInterrupt() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) { //Button gedrückt
    fill_solid( leds, NUM_LEDS, CHSV(160,255,255) );  //set color of pixels - blue
    FastLED.show();  // display the pixels
  }
  if (buttonState == LOW) { //Button losgelassen
    FastLED.clear();
    FastLED.show();  // display the pixels
  }
}

