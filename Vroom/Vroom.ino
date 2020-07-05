#include <Arduino_LSM6DS3.h>
#include <ArduinoBLE.h>
#include <Sabertooth.h>

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

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  
  SabertoothSetup();
  IMUSetup();
  BluetoothSetup();
}

void loop()
{

}

void SabertoothSetup()
{
  ST.autobaud();
  ST.drive(0);
  ST.turn(0);
}

void IMUSetup()
{
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void BluetoothSetup()
{
  if (!BLE.begin()) {
    Serial.println("Failed to initialize Bluetooth!");
    while (1);
  }
}
