#include <Adafruit_NeoPixel.h>
#include "HID-Project.h"  // https://github.com/NicoHood/HID

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
int16_t neo_brightness = 16; // initialize with 20 brightness (out of 255)
uint32_t red = strip.Color(255, 0, 0);
uint32_t white = strip.Color(255, 255, 255);
bool last_switch = true;

void setup() {
  // Serial.begin(9600);
  Keyboard.begin();
  strip.begin();
  strip.setPixelColor(0,red);
  strip.setBrightness(neo_brightness);
  strip.show();
  
  pinMode(PIN_SWITCH, INPUT_PULLDOWN);
}

void loop() {
  bool curr_switch = digitalRead(PIN_SWITCH);
  if (curr_switch != last_switch) {
    if (curr_switch) {
      // Serial.println("Pressed");
      strip.setPixelColor(0,white);
      strip.setBrightness(255);
      strip.show();
    } else {
      
      // use this for d3 / .
      Keyboard.write(HID_KEYBOARD_PERIOD_AND_GREATER_THAN);

      // use this for pixera / spacebar
      //Keyboard.write(' ');

      // Serial.println("Released");
      strip.setBrightness(neo_brightness);
      strip.setPixelColor(0,red);
      strip.show();
    }
    last_switch = curr_switch;
  }

  strip.show();
  delay(10);
}
