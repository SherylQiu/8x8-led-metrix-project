// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6  // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64  // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500  // Time (in milliseconds) to pause between pixels

int colorState = 0;

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.setBrightness(20);
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)

  colorState = EEPROM.read(0);

  colorState++;

  if (colorState > 6) {
    colorState = 0;
  }

  EEPROM.write(0, colorState);


}

void loop() {
  showtime();
}
void showtime() {

  if (colorState == 0) {
    mushroom();
  } else if (colorState == 1) {
    colorsparcle();
  } else if (colorState == 2) {
    heart();
  }else if(colorState == 3){
    frog();
  }else if(colorState == 4){
    dimend();
  }else if(colorState == 5){
    coke();
  }else if(colorState == 6){
    popcorn();
  }else{
    example();
  }
}


// color area
uint32_t blank = pixels.Color(0, 0, 0);
uint32_t white = pixels.Color(200, 200, 200);
uint32_t gray = pixels.Color(18, 18, 23);
uint32_t red = pixels.Color(200, 0, 0);
uint32_t darkred = pixels.Color(25, 10, 10);
uint32_t green = pixels.Color(0, 200, 0);
uint32_t darkgreen = pixels.Color(10, 20, 10);
uint32_t yellow = pixels.Color(250, 150, 0);
uint32_t darkyellow = pixels.Color(25, 15, 0);
uint32_t blue = pixels.Color(0, 50, 200);
uint32_t darkblue = pixels.Color(0, 10, 20);
uint32_t purple = pixels.Color(200, 0, 200);
uint32_t darkpurple = pixels.Color(20, 0, 30);
uint32_t cyan = pixels.Color(0, 230, 200);
uint32_t darkcyan = pixels.Color(0, 25, 20);

void mushroom() {

  // Row 1
  int32_t mushroom[64] = {
    blank, red, red, red, blank, blank, blank, blank,
    red, white, red, darkred, gray, gray, gray, blank,
    red, red, red, darkred, gray, white, white, gray,
    red, red, red, darkred, white, white, white, gray,
    white, red, red, darkred, white, white, gray, gray,
    red, red, red, darkred, white, white, white, gray,
    red, red, white, darkred, gray, gray, gray, blank,
    blank, red, red, red, blank, blank, blank, blank
  };

  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, mushroom[i]);
    pixels.show();
  }
}

void frog() {

  uint32_t frog[64] = {
    blank, blank, blank, blank, darkgreen, darkgreen, darkgreen, blank,
    blank, blank, blank, darkgreen, green, green, green, darkgreen,
    blank, blank, darkgreen, green, green, darkgreen, green, darkgreen,
    blank, darkgreen, green, green, green, darkgreen, green, darkgreen,
    blank, darkgreen, green, green, green, green, darkgreen, darkgreen,
    darkgreen, green, darkgreen, green, darkgreen, darkgreen, green, darkgreen,
    blank, darkgreen, green, green, darkgreen, blank, darkgreen, darkgreen,
    blank, blank, darkgreen, darkgreen, blank, blank, blank, blank
  };

  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, frog[i]);
    pixels.show();
  }
}

void heart() {

  uint32_t heart[64] = {
    blank, blank, red, red, red, blank, blank, blank,
    blank, red, red, red, red, red, blank, blank,
    blank, red, red, red, red, red, red, blank,
    blank, blank, red, red, red, red, red, red,
    blank, blank, red, red, red, red, red, red,
    blank, red, red, red, red, red, red, blank,
    blank, red, red, red, red, red, blank, blank,
    blank, blank, red, red, red, blank, blank, blank
  };

  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, heart[i]);
    pixels.show();
  }
}

void colorsparcle(){

  uint32_t star1[64] = {
    blank, blank, blank, blank, blank, blank, darkyellow, blank,
    blank, blank, blank, blank, yellow, darkyellow, blank, darkyellow,
    blank, blank, yellow, darkyellow, blank, blank, darkyellow, blank,
    blank, blank, blank, blank, blank, blank, yellow, blank,
    blank, darkyellow, blank, blank, blank, darkyellow, blank, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, blank, blank, darkyellow, blank, blank, blank, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
  };

  uint32_t star2[64] = {
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, blank, yellow, blank, darkyellow, blank, blank, blank,
    blank, yellow, darkyellow, yellow, blank, blank, blank, blank,
    blank, blank, yellow, blank, blank, blank, darkyellow, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, blank, blank, blank, blank, yellow, blank, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, yellow, blank, blank, blank, blank, blank, blank,
  };

  uint32_t star3[64] = {
    blank, blank, yellow, blank, blank, blank, blank, blank,
    blank, blank, darkyellow, blank, blank, blank, blank, blank,
    yellow, darkyellow, blank, darkyellow, yellow, blank, blank, blank,
    blank, blank, darkyellow, blank, blank, blank, blank, blank,
    blank, blank, yellow, yellow, blank, yellow, blank, blank,
    blank, blank, blank, blank, yellow, darkyellow, yellow, blank,
    blank, yellow, blank, blank, blank, yellow, blank, blank,
    yellow, darkyellow, yellow, blank, blank, blank, blank, blank,
  };

  uint32_t star4[64] = {
    blank, blank, darkyellow, blank, blank, blank, blank, blank,
    blank, blank, blank, blank, blank, blank, yellow, blank,
    darkyellow, blank, blank, blank, darkyellow, blank, blank, blank,
    blank, blank, blank, yellow, blank, blank, blank, blank,
    blank, blank, yellow, darkyellow, yellow, darkyellow, blank, blank,
    blank, yellow, blank, yellow, darkyellow, blank, darkyellow, yellow,
    blank, darkyellow, blank, blank, blank, darkyellow, blank, blank,
    darkyellow, blank, darkyellow, yellow, blank, yellow, blank, blank,
  };

  uint32_t star5[64] = {
    blank, blank, blank, blank, blank, blank, yellow, blank,
    blank, blank, blank, blank, blank, yellow, darkyellow, yellow,
    blank, blank, blank, yellow, blank, blank, yellow, blank,
    blank, blank, blank, darkyellow, blank, darkyellow, blank, blank,
    blank, yellow, darkyellow, blank, darkyellow, yellow, blank, blank,
    blank, darkyellow, blank, darkyellow, blank, blank, blank, darkyellow,
    blank, blank, blank, yellow, blank, blank, blank, blank,
    blank, blank, blank, darkyellow, blank, darkyellow, blank, blank,
  };

  while(true){
    delay(100);
    for (int i = 0; i < 64; i++) {
      pixels.setPixelColor(i, star1[i]);
      pixels.show();
    }
    delay(100);
    for (int i = 0; i < 64; i++) {
      pixels.setPixelColor(i, star2[i]);
      pixels.show();
    }
    delay(100);
    for (int i = 0; i < 64; i++) {
      pixels.setPixelColor(i, star3[i]);
      pixels.show();
    }
    delay(100);
    for (int i = 0; i < 64; i++) {
      pixels.setPixelColor(i, star4[i]);
      pixels.show();
    }
    delay(100);
    for (int i = 0; i < 64; i++) {
      pixels.setPixelColor(i, star5[i]);
      pixels.show();
    }
    

  }
}

void dimend(){

  uint32_t dimend[64] = {
    blank, blank, blank, darkcyan, darkcyan, blank, blank, blank,
    blank, blank, darkcyan, cyan, darkcyan, darkcyan, blank, blank,
    blank, darkcyan, cyan, cyan, darkcyan, darkcyan, darkcyan, blank,
    blank, darkcyan, cyan, cyan, darkcyan, darkcyan, darkcyan, darkcyan,
    blank, darkcyan, cyan, cyan, darkcyan, cyan, cyan, darkcyan,
    blank, darkcyan, cyan, cyan, darkcyan, cyan, darkcyan, blank,
    blank, blank, darkcyan, cyan, darkcyan, darkcyan, blank, blank,
    blank, blank, blank, darkcyan, darkcyan, blank, blank, blank,
  };

  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, dimend[i]);
    pixels.show();
  }
}

void coke(){

  uint32_t coke[64] = {
    blank, blank, blank, blank, blank, blank, blank, blank,
    gray, darkblue, darkblue, darkblue, darkblue, darkblue, darkblue, darkblue,
    white, darkblue, red, white, blue, blue, darkblue, darkblue,
    white, darkblue, red, white, blue, blue, darkblue, darkblue,
    white, darkblue, red, red, white, blue, darkblue, darkblue,
    white, darkblue, red, red, white, blue, darkblue, darkblue,
    gray, darkblue, darkblue, darkblue, darkblue, darkblue, darkblue, darkblue,
    blank, blank, blank, blank, blank, blank, blank, blank,
  };

  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, coke[i]);
    pixels.show();
  }
}

void popcorn(){
  uint32_t popcorn1[64] = {
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, white, yellow, red, red, red, red, blank,
    white, yellow, white, red, red, red, red, red,
    yellow, white, yellow, gray, gray, gray, gray, gray,
    white, yellow, white, red, red, red, red, red,
    yellow, white, yellow, gray, gray, gray, gray, gray,
    blank, yellow, white, red, red, red, red, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
  };

  uint32_t popcorn2[64] = {
    blank, blank, blank, blank, blank, blank, blank, blank,
    blank, yellow, white, red, red, red, red, blank,
    yellow, white, yellow, red, red, red, red, red,
    white, yellow, white, gray, gray, gray, gray, gray,
    yellow, white, yellow, red, red, red, red, red,
    white, yellow, white, gray, gray, gray, gray, gray,
    blank, white, yellow, red, red, red, red, blank,
    blank, blank, blank, blank, blank, blank, blank, blank,
  };

  while(true){
  delay(100);
  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, popcorn1[i]);
    pixels.show();
  }
  delay(100);
  for (int i = 0; i < 64; i++) {
    pixels.setPixelColor(i, popcorn2[i]);
    pixels.show();
  }
  }
}
