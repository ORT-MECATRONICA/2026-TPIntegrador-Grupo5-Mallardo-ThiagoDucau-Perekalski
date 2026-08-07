#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);  
  bool status = bme.begin(0x76);
  if (!status) {
    Serial.println("Error al conectar bme");
    while (1); //Frenar el programa
 }
}

void loop() {
  Serial.print("Temp:"); Serial.println(bme.readTemperature());
  Serial.print("Humidity:"); Serial.println(bme.readHumidity());
}