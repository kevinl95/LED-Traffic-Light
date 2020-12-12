#include <Adafruit_NeoPixel.h>

const byte redswitchPin = 8;
const byte greenswitchPin = 9;
Adafruit_NeoPixel redring = Adafruit_NeoPixel(24, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel greenring = Adafruit_NeoPixel(24, 7, NEO_GRB + NEO_KHZ800);

void setup ()
{
  pinMode (redswitchPin, INPUT_PULLUP);
  pinMode (greenswitchPin, INPUT_PULLUP);

  redring.begin();
  greenring.begin();
  redring.setBrightness(100);
  greenring.setBrightness(100);
  redring.show(); // Initialize all pixels to 'off'
  greenring.show();
}  // end of setup

void loop ()
{
  if (digitalRead(redswitchPin) == HIGH)
  {
    redring.fill(redring.Color(255, 0, 0));
  } else {
    redring.clear();  // Off
  }
  if (digitalRead(greenswitchPin) == HIGH)
  {
    greenring.fill(greenring.Color(0, 255, 0));
  } else {
    greenring.clear();  // Off
  }
}  // end of loop
