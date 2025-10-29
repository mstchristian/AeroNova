//     :::     :::::::::: :::::::::   ::::::::  ::::    :::  ::::::::  :::     :::     :::     
//   :+: :+:   :+:        :+:    :+: :+:    :+: :+:+:   :+: :+:    :+: :+:     :+:   :+: :+:   
//  +:+   +:+  +:+        +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+    +:+ +:+     +:+  +:+   +:+  
// +#++:++#++: +#++:++#   +#++:++#:  +#+    +:+ +#+ +:+ +#+ +#+    +:+ +#+     +:+ +#++:++#++: 
// +#+     +#+ +#+        +#+    +#+ +#+    +#+ +#+  +#+#+# +#+    +#+  +#+   +#+  +#+     +#+ 
// #+#     #+# #+#        #+#    #+# #+#    #+# #+#   #+#+# #+#    #+#   #+#+#+#   #+#     #+# 
// ###     ### ########## ###    ###  ########  ###    ####  ########      ###     ###     ###
// AeroNova_Static.ino - Made by AeroNova Group

// --------------- Libraries --------------- //
#include "Adafruit_BME280.h"
#include <SPI.h>

// -------------- Definitions -------------- //
#define BME_CS 10
#define BME_MOSI 11
#define BME_MISO 12
#define BME_SCK 13

// ----------------- BME280 ---------------- //
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

// --------------- Functions --------------- //
void printTab() {
  Serial.print(F("\t"));
}

void printHeader() {
  Serial.println();
  Serial.println("AeroNova Static");
  Serial.println("Made by AeroNova Group");
  Serial.println("Repository: https://github.com/mstchristian/AeroNova");
  Serial.println("----------------------------------------------------------------");

  Serial.print("t"); printTab();
  Serial.println("h");
}

// ------------ Main Functions ------------- //
void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!bme.begin()) {
    while(1);
  }

  printHeader();
}

void loop() {
  Serial.print(bme.readTemperature()); printTab();
  Serial.println(bme.readHumidity());

  delay(100);
}