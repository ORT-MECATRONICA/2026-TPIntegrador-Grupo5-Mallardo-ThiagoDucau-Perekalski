// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C, columnas, filas

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Grupo 5");

  lcd.setCursor(0, 1);
  lcd.print("5LC 2026");
}

void loop() {
  // No hace falta repetir nada, el texto queda fijo en pantalla
}