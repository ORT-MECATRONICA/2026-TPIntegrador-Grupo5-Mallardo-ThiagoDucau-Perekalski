// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>

const int ldrPin = 34; // Pin analogico

void setup() {
  Serial.begin(115200);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("Valor LDR: ");
  Serial.println(ldrValue);
  delay(1000);
}
