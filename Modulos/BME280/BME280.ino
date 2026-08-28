// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  bool status = bmp.begin(0x76);
  if (!status) {
    Serial.println("Error al conectar bmp");
    while (1); //Frenar el programa
  }
}

void loop() {
  Serial.print("Temperatura: "); Serial.println(bmp.readTemperature());
  Serial.print("Pressure (hPa):"); Serial.println(bmp.readPressure() / 100.0F);
  delay(5000);
}