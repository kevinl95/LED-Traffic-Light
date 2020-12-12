#include <Adafruit_NeoPixel.h>

const byte redswitchPin = 8;
const byte greenswitchPin = 9;
Adafruit_NeoPixel redring = Adafruit_NeoPixel(24, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel greenring = Adafruit_NeoPixel(24, 6, NEO_GRB + NEO_KHZ800);

void setup ()
{
  pinMode (redswitchPin, INPUT_PULLUP);
  pinMode (greenswitchPin, INPUT_PULLUP);
  Serial.begin (115200);
  redring.begin();
  greenring.begin();
  redring.setBrightness(100);
  greenring.setBrightness(100);
  redring.show(); // Initialize all pixels to 'off'
  greenring.show();
}  // end of setup

void loop ()
{
  if (digitalRead(redswitchPin) == LOW)
  {
    redring.fill(redring.Color(255, 0, 0));
    redring.show();
  } else {
    redring.clear();  // Off
    redring.show();
  }
  if (digitalRead(greenswitchPin) == LOW)
  {
    greenring.fill(greenring.Color(0, 255, 0));
    greenring.show();
  } else {
    greenring.clear();  // Off
    greenring.show();
  }
}  // end of loop
