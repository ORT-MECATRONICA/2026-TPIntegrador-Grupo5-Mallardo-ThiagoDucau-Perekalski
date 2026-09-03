// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>

const int ldrPin = 34; // Pin analogico conectado entre la R de 10k y el LDR
const int ledPin = 2;  // Pin para el LED indicador

// A mayor oscuridad, mayor resistencia del LDR, por lo que el pin lee un voltaje mayor.
const int umbralOscuridad = 2000; 

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("Valor LDR: ");
  Serial.print(ldrValue);
  
  if (ldrValue > umbralOscuridad) {
    digitalWrite(ledPin, HIGH); // Prende el LED porque esta oscuro
    Serial.println(" -> Oscuro: LED ENCENDIDO");
  } else {
    digitalWrite(ledPin, LOW);  // Apaga el LED porque hay luz
    Serial.println(" -> Luz: LED APAGADO");
  }
  
  delay(1000);
}
