// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>

const int mq2Pin = 35; // Pin analogico para el MQ-2 (o potenciometro)
const int ledPin = 2;  // Pin para el LED indicador

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  
  Serial.print("Valor MQ-2: ");
  Serial.println(sensorValue);
  
  if (sensorValue > 3500) {
    digitalWrite(ledPin, HIGH); // Prende el LED
    Serial.println("¡Alerta! Nivel superado.");
  } else {
    digitalWrite(ledPin, LOW);  // Apaga el LED
  }
  
  delay(1000);
}
