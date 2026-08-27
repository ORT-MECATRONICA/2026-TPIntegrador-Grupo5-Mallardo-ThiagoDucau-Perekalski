#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configura la dirección del I2C en 0x27, con 16 columnas y 2 filas.
// Nota: Algunas pantallas usan la dirección 0x3F. Si 0x27 no funciona, cámbialo.
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Inicializa el LCD
  lcd.init();
  
  // Enciende la luz de fondo
  lcd.backlight();
  
  // Posiciona el cursor en la primera columna (0) de la primera fila (0)
  lcd.setCursor(0, 0);
  lcd.print("Hola ESP32!");
}

void loop() {
  // Posiciona el cursor en la primera columna (0) de la segunda fila (1)
  lcd.setCursor(0, 1);
  lcd.print("Segundos: ");
  // Imprime el tiempo transcurrido
  lcd.print(millis() / 1000);
  
  delay(1000); // Espera un segundo antes de actualizar
}