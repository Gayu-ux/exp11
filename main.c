#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BMP280 bmp;
void setup() {
 Serial.begin(9600);
 while (!Serial);
 Serial.println(F("BMP280 Sensor Test"));
 Wire.begin(); // Use default SDA=GP0, SCL=GP1 for Mbed core
 if (!bmp.begin(0x76)) {
 Serial.println(F("Could not find BMP280 sensor! Check wiring."));
 while(1);
 }
 bmp.setSampling(
 Adafruit_BMP280::MODE_NORMAL,
 Adafruit_BMP280::SAMPLING_X2,
 Adafruit_BMP280::SAMPLING_X16,
 Adafruit_BMP280::FILTER_X16,
 Adafruit_BMP280::STANDBY_MS_500
 );
}
 void loop() {
 Serial.print(F("Temperature = "));
 Serial.print(bmp.readTemperature());
 Serial.println(" *C");
 Serial.print(F("Pressure = "));
 Serial.print(bmp.readPressure() / 100.0F);
 Serial.println(" hPa");
 Serial.print(F("Approx. Altitude = "));
 Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
 Serial.println(" m");
 Serial.println();
 delay(2000);
}
