//***************************************************************
// The whole strip will show the same color.  When the button
// is pressed and held down the strip will cycle through the
// rainbow.  Release the button to stop on a new color.
//
// This is how the button is wired for this example:
// http://i.imgur.com/hOgQwjX.jpg
//
// Marc Miller, Jan 2019
//***************************************************************

#include <Bounce.h>
#include "FastLED.h"

// Set the digital pin for the pushbutton, and declare the button
//const uint8_t ButtonPin = 4;
//Button Push_Button(ButtonPin, true, true, 100);
#define BUTTON 4
Bounce bouncer = Bounce( BUTTON,5 );


//---------------------------------------------------------------

//#define DATA_PIN    11
//#define CLK_PIN   13
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
  pinMode(BUTTON,INPUT);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 14>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
}


//---------------------------------------------------------------
void loop()
{
  //readbutton();  // check the button to see if it's pressed
  bouncer.update();

  // Get the update value
  int value = bouncer.read();

   if ( value == HIGH) {
      hue = hue + 1;   //can be either + or - some value
  }
  fill_solid( leds, NUM_LEDS, CHSV(hue,255,255) );  //set color of pixels
  FastLED.show();  // display the pixels

}//end_main_loop
