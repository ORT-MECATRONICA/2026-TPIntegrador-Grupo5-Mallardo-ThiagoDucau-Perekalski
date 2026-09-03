//Grupo 5: Thiago Ducau, Marco Mallardo, Ramiro Perekalski
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configura la dirección del I2C en 0x27, con 16 columnas y 2 filas.
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Inicializa el LCD
  lcd.init();
  
  // Enciende la luz de fondo
  lcd.backlight();
  
  // Posiciona el cursor en la primera columna de la primera fila
  lcd.setCursor(0, 0);
  lcd.print("Prueba LCD");
  lcd.setCursor(0, 1);
  lcd.print("Grupo 5");
}

void loop() {
}