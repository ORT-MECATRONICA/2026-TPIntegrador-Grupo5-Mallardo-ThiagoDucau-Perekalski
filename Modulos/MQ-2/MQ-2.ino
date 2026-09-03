// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>

const int mq2Pin = 35; // Pin analogico simulando el MQ-2 con un potenciometro

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  Serial.print("Valor MQ-2 (simulado): ");
  Serial.println(sensorValue);
  delay(1000);
}
