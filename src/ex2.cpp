


#include "Arduino.h"


/****************************************************/
void setup() {
  Serial.begin(115200);
  pinMode(33, INPUT);
}


/****************************************************/
void loop(void) 
{
    int value = analogRead(33);
  int minimum = value;
  int maximum = value;
  int sum = value;

  // Первый замер уже сделан, делаем ещё 9.
  for (int i = 0; i < 9; i++) {
    value = analogRead(33);

    if (value < minimum) {
      minimum = value;
    }

    if (value > maximum) {
      maximum = value;
    }

    sum = sum + value;
  }

  int average = sum / 10;

  Serial.print("min=");
  Serial.print(minimum);
  Serial.print(" max=");
  Serial.print(maximum);
  Serial.print(" avg=");
  Serial.println(average);

  delay(1000);
}
