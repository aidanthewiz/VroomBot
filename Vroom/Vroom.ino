#include <ArduinoBLE.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

/* 
  Sabertooth 2x32 DIP Switches - Baud 9600
  1 - On
  2 - Off
  3 - On
  4 - Off
  5 - On
  6 - On

  8Bitdo Controller MAC - e4:17:d8:4f:f7:05
*/

// Defined in arduino_secrets.h
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int status = WL_IDLE_STATUS;

void connectToWiFi()
{
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (1);
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);

    delay(10000);
  }
  
  Serial.print("Successfully connected to ");
  Serial.println(ssid);
}

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  connectToWiFi();

  // if (!BLE.begin()) {
  //   Serial.println("Starting BLE failed!");
  //   while (1);
  // }

  // Serial.println("BLE Central Scan");
  // BLE.scanForAddress("e4:17:d8:4f:f7:05");
  // BLEDevice peripheral = BLE.available();
  // if (peripheral) {
  //     Serial.println("BLE Connected");
  // }
}

void loop()
{

}
