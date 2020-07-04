#include <ArduinoBLE.h>
#include <Sabertooth.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

/*
  Sabertooth 2x32 DIP Switches - Baud 9600
  1 - Off
  2 - Off
  3 - Off
  4 - On
  5 - On
  6 - On

  Arduino TX->1  ->  Sabertooth S1
  Arduino GND    ->  Sabertooth 0V
  Arduino VIN    ->  Sabertooth 5V (OPTIONAL, if you want the Sabertooth to power the Arduino)

  8Bitdo Controller MAC - e4:17:d8:4f:f7:05
*/

Sabertooth ST(128);

// Defined in arduino_secrets.h
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int status = WL_IDLE_STATUS;

void setup()
{
  SabertoothSetup();
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

void SabertoothSetup()
{
  SabertoothTXPinSerial.begin(9600);
  while (!SabertoothTXPinSerial);
  
  ST.autobaud();
  ST.drive(0);
  ST.turn(0);
}
