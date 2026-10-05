#include <Arduino.h>

const int ledPins[] = {26, 27, 12, 14};

int count = 0;

bool lastReading = LOW;
bool buttonState = LOW;
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(25, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  bool reading = digitalRead(25);

  // Защита от дребезга кнопки.
  if (reading != lastReading) {
    lastChangeTime = millis();
  }

  if (millis() - lastChangeTime >= 30) {
    if (reading != buttonState) {
      buttonState = reading;

      // Считаем только новое нажатие.
      if (buttonState == HIGH) {
        count++;

        if (count > 4) {
          count = 0;
        }

        for (int i = 0; i < 4; i++) {
          if (i < count) {
            digitalWrite(ledPins[i], HIGH);
          } else {
            digitalWrite(ledPins[i], LOW);
          }
        }

        Serial.print("count=");
        Serial.println(count);
      }
    }
  }

  lastReading = reading;
}