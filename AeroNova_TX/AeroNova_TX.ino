#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10


#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

unsigned long delayTime;

void setup() {
  Serial.begin(9600);
  Serial.println();

  bool status;
  status = bme.begin();

  if(!status) {
    Serial.println("Sensor BME280 not found!");
    while (1);
  }

  delayTime = 1000;
  Serial.println("Temperature, Pressure, Altitude, Humidity");
}

void loop() {
  Serial.print(bme.readTemperature());
  Serial.print(" *C, ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.print(" hPa, ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print(" m, ");
  Serial.print(bme.readHumidity());
  Serial.print(" %");
  Serial.println();
  delay(delayTime);
}