// Grupo 5: Marco Mallardo, Thiago Ducau, Ramiro Perekalski

#include <Arduino.h>
#include <ld2410.h>

#define MONITOR_SERIAL Serial
#define RADAR_SERIAL Serial1
#define RADAR_RX_PIN 16
#define RADAR_TX_PIN 17
 
ld2410 radar;
uint32_t ultimaLectura = 0;
 
void setup() {
  MONITOR_SERIAL.begin(115200);
  RADAR_SERIAL.begin(256000, SERIAL_8N1, RADAR_RX_PIN, RADAR_TX_PIN);
  
  delay(500);
  MONITOR_SERIAL.print(F("Iniciando sensor radar LD2410... "));
 
  if (radar.begin(RADAR_SERIAL)) {
    MONITOR_SERIAL.println(F("OK"));
  } else {
    MONITOR_SERIAL.println(F("Error de conexion"));
  }
}
 
void loop() {
  radar.read();
  
  // Reportar cada 1000ms si esta conectado
  if (radar.isConnected() && millis() - ultimaLectura > 1000) {
    ultimaLectura = millis();
    
    if (radar.presenceDetected()) {
      if (radar.stationaryTargetDetected()) {
        MONITOR_SERIAL.print(F("Objetivo estatico: "));
        MONITOR_SERIAL.print(radar.stationaryTargetDistance());
        MONITOR_SERIAL.print(F("cm energia: "));
        MONITOR_SERIAL.print(radar.stationaryTargetEnergy());
        MONITOR_SERIAL.print(F(" | "));
      }
      
      if (radar.movingTargetDetected()) {
        MONITOR_SERIAL.print(F("Objetivo en movimiento: "));
        MONITOR_SERIAL.print(radar.movingTargetDistance());
        MONITOR_SERIAL.print(F("cm energia: "));
        MONITOR_SERIAL.print(radar.movingTargetEnergy());
      }
      MONITOR_SERIAL.println();
    } else {
      MONITOR_SERIAL.println(F("Sin presencia"));
    }
  }
}
