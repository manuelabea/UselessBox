#include "FastLED.h"
#include <Arduino.h>
/*
Ein Kabel (z.B. rot) an PIN 2 stecken. Das andere (weiß) muss auf Ground (PIN G) gesteckt werden.
Nur so funktioniert es.
*/

const int togglePin = 2;
const int buttonPin = 4;
const int temporalThreshold = 100; // wie lange wird gebraucht bis wir eine state Änderung als einen neuen State akzeptieren

volatile int actionCounter = 0; // variable to count which action we're at
int currentAction = 0;

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
#define FRAMES_PER_SECOND  120

uint8_t hue;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns


void setup() {
  actionCounter = 0;
  currentAction = 0;
  pinMode(togglePin,INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(togglePin), countActions, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);

  FastLED.addLeds<NEOPIXEL, 14>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

}

void loop() {

  if (currentAction != actionCounter) {
    currentAction = actionCounter;
    chooseAction(currentAction);
  }

}

void countActions() {
  if (lastUpdate + temporalThreshold < millis() && blocked == false) {
    Serial.println("ActionCounter start Interrupt " + String(actionCounter));
    blocked = true;
    lastUpdate = millis(); // merkt sich wann der Änderungsvorgang gestartet wurde

    delay(50); // wichtig!! Da im Wechsel noch viel passieren kann, warten wir bis sich der State endgültig stabilisiert hat
    toggleState = digitalRead(togglePin); // lesen den Status aus

    if (toggleState == LOW) {
      actionCounter += 1;
      Serial.println("Action iterated - " + String(actionCounter));
    }
    blocked = false; // Methode wird freigegeben
    Serial.println("ActionCounter end Interrupt: " + String(actionCounter));
  }
}


void buttonInterrupt() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) { //Button gedrückt
    fill_solid( leds, NUM_LEDS, CHSV(160,255,255) );  //set color of pixels
    FastLED.show();  // display the pixels
  }
  if (buttonState == LOW) { //Button losgelassen
    FastLED.clear();
    FastLED.show();  // display the pixels
  }
}

void chooseAction(int action) {
  switch(action) {
    case 1:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 0, 255, 255) );  //rot
      FastLED.show();  // display the pixels
      break;
    case 2:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 45, 255, 255) );  //gelb
      FastLED.show();  // display the pixels
      break;
    case 3:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 95, 255, 255) );  //grün
      FastLED.show();  // display the pixels
      break;
    case 4:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 127, 255, 255) );  //cyan
      FastLED.show();  // display the pixels
      break;
    case 5:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 160, 255, 255) );  //blau
      FastLED.show();  // display the pixels
      break;
    case 6:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 210, 255, 255) );  //magenta
      FastLED.show();  // display the pixels
      break;
    default:
      //Serial.println("Action: " + String(actionCounter));
      fill_solid( leds, NUM_LEDS, CHSV( 100, 0, 255) ); //white
      break;
  }

}

