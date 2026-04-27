// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  
  pixels.setBrightness(20);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  int i;
  uint32_t red = pixels.Color(200,0,0);
  uint32_t darkred = pixels.Color(20,10,10);
  uint32_t white = pixels.Color(200,200,200);
  uint32_t gray = pixels.Color(18,18,25);
  uint32_t blank = pixels.Color(0,0,0);
  //pixels.setPixelColor(0, darkred);
  for (i = 1; i < 4; i++){
    pixels.setPixelColor(i, red);
  }
  //pixels.setPixelColor(4, darkred);

  pixels.setPixelColor(5, blank);
  pixels.setPixelColor(6, blank);
  //pixels.setPixelColor(7, darkred);
  pixels.setPixelColor(63, blank);

  for (i = 8; i <= 10; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(11, darkred);
  pixels.setPixelColor(9, white);

  for (i = 12; i <= 15; i++){
    pixels.setPixelColor(i, gray);
  }
   pixels.setPixelColor(12, gray);
    pixels.setPixelColor(15, blank);



  for (i = 16; i <= 19; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(19, darkred);

  for (i = 24; i <= 27; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(27, darkred);

  for (i = 32; i <= 35; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(35, darkred);
  pixels.setPixelColor(32, white);

  for (i = 40; i <= 43; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(43, darkred);

  for (i = 48; i <= 51; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(51, darkred);
  pixels.setPixelColor(50, white);

  for (i = 56; i <= 61; i++){
    pixels.setPixelColor(i, red);

  }
  pixels.setPixelColor(61, darkred);
  pixels.setPixelColor(60, blank);
  pixels.setPixelColor(56, blank);

  for (i = 20; i <= 23; i++){
    pixels.setPixelColor(i, white);
  }
  pixels.setPixelColor(20, gray);
  pixels.setPixelColor(23, gray);

  for (i = 28; i <= 31; i++){
    pixels.setPixelColor(i, white);
  }
  pixels.setPixelColor(31, gray);


  for (i = 36; i <= 39; i++){
    pixels.setPixelColor(i, white);
  }
  pixels.setPixelColor(39, gray);

  for (i = 44; i <= 47; i++){
    pixels.setPixelColor(i, white);
  }
  pixels.setPixelColor(47, gray);

  for (i = 52; i <= 55; i++){
    pixels.setPixelColor(i, gray);
  }
  pixels.setPixelColor(55, blank);
  pixels.setPixelColor(52, gray);

  for (i = 61; i <= 62; i++){
    pixels.setPixelColor(i, blank);
  }
      pixels.setPixelColor(38, gray);



    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(5000); // Pause before next pass through loop
    
}
