// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        13 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 25 // Time (in milliseconds) to pause between pixels
int y = 0;
void setup() {
  Serial.begin(9600); 
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1); 
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
 
    for (int x = 1; x < 256 ; x++) {
      pixels.setPixelColor(y, pixels.Color(255, x, 0));
      pixels.show();
      //   pixels.clear();
      Serial.println(x);
      delay(DELAYVAL);

      if (x == 255) {
        pixels.setPixelColor(7, pixels.Color(255, 255, 255));
        pixels.show();
        delay(1000);
      } else {
        pixels.setPixelColor(7, pixels.Color(0, 0, 0));
        pixels.show();
      }
    }
    for (int x = 254; x > -1; x--) {
      pixels.setPixelColor(y, pixels.Color(255, x, 0));
      pixels.show();
      //  pixels.clear();
      Serial.println(x);
      delay(DELAYVAL);

      if (x == 0) {
        pixels.setPixelColor(7, pixels.Color(255, 255, 255));
        pixels.show();
        delay(1000);
      } else {
        pixels.setPixelColor(7, pixels.Color(0, 0, 0));
        pixels.show();
      }
    }


  }











  /*
    for (int x = 0; x < NUMPIXELS-1 ; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 150, 0));
      pixels.show();
      pixels.clear();

      delay(DELAYVAL);
    }
    for (int x = NUMPIXELS-1; x > 0; x--) {
      pixels.setPixelColor(x, pixels.Color(0, 150, 0));
      pixels.show();
      pixels.clear();

      delay(DELAYVAL);
    }
  */
