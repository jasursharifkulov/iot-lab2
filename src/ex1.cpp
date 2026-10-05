


#include "Arduino.h"

#define RED_LED_PIN 26

const int ledPins[] = {26, 27, 12, 14};
const int chasePins[] = {26, 27, 12, 14, 12, 27};
const char* chaseNames[] = {
  "RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"
};
int stepIndex = 0;

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}


/****************************************************/
void loop(void) 
{
    for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  digitalWrite(chasePins[stepIndex], HIGH);

  Serial.print("chase=");
  Serial.println(chaseNames[stepIndex]);

  delay(150);
  stepIndex = (stepIndex + 1) % 6;
}
