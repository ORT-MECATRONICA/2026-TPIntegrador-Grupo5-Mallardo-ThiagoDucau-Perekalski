// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
      delay(1);
  }

  if (!ina219.begin()) {
    Serial.println("Error al conectar INA219");
    while (1); // Frenar el programa
  }
}

void loop() {
  float busvoltage = 0;
  float current_mA = 0;
  
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  
  Serial.print("Voltaje: "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Corriente: "); Serial.print(current_mA); Serial.println(" mA");
  
  delay(2000);
}
