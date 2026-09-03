// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>

// El sensor HLK-LD2410 tiene un pin OUT que se pone en ALTO cuando detecta presencia
const int radarOutPin = 32; 

void setup() {
  Serial.begin(115200);
  pinMode(radarOutPin, INPUT);
}

void loop() {
  int presencia = digitalRead(radarOutPin);
  
  if (presencia == HIGH) {
    Serial.println("Presencia detectada!");
  } else {
    Serial.println("Sin presencia");
  }
  
  delay(500);
}
