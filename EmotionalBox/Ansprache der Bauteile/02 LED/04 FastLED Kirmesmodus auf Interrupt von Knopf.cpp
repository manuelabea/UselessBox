//***************************************************************
/*
Der Interrupt wird wohl nicht erkannt. Wieso, keine Ahnung.
*/
//***************************************************************

#include <Bounce.h>
#include "FastLED.h"
#include <avr/io.h>
#include <avr/interrupt.h>


// Set the digital pin for the pushbutton, and declare the button

#define BUTTON 4
Bounce bouncer = Bounce( BUTTON,5 );
volatile byte state = LOW;
byte oldState = LOW;;

//---------------------------------------------------------------

#define LED_TYPE    NEOPIXEL
#define COLOR_ORDER GRB
#define NUM_LEDS    28
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 255

uint8_t hue;

//---------------------------------------------------------------
void setup() {
  Serial.begin(115200);  // Allows serial monitor output (check baud rate)
  delay(1500); // Startup delay
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, CHANGE);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 14>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
}


//---------------------------------------------------------------
void loop()
{
  if (state != oldState) {
    oldState = state;
  }

  if (oldState == HIGH) { //Wenn an
    hue = hue + 1;   //can be either + or - some value
    fill_solid( leds, NUM_LEDS, CHSV(hue,255,255) );  //set color of pixels
    FastLED.show();  // display the pixels
  } else {
    FastLED.clear();
    FastLED.show();
  }

}//end_main_loop

void buttonPressed() {
  //if (digitalRead (BUTTON) == HIGH)
  if (bouncer.read() == HIGH ){
    Serial.print("HIGH");
    state = HIGH;
  } else {
    Serial.print("LOW");
    state = LOW;
  }
}  // end of switchPressed
