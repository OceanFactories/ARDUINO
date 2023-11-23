#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

#include "BluetoothSerial.h"

#define USE_NAME // Comment this to use MAC address instead of a slaveName
//const char *pin = "1234"; // Change this to reflect the pin expected by the real slave BT device

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

#ifdef USE_NAME
  String slaveName = "ESP32-BT-Slave"; // Change this to reflect the real name of your slave BT device
//#else
 // String MACadd = "AA:BB:CC:11:22:33"; // This only for printing
//  uint8_t address[6]  = {0xAA, 0xBB, 0xCC, 0x11, 0x22, 0x33}; // Change this to reflect real MAC address of your slave BT device
#endif

String myName = "ESP32-BT-Master";

void setup() {
  bool connected;
  Serial.begin(115200);
  servo1.attach(12);
  servo2.attach(13);
  servo3.attach(2);
  servo4.attach(15);
  
  SerialBT.begin(myName, true);
  Serial.printf("The device \"%s\" started in master mode, make sure slave BT device is on!\n", myName.c_str());



  // connect(address) is fast (up to 10 secs max), connect(slaveName) is slow (up to 30 secs max) as it needs
  // to resolve slaveName to address first, but it allows to connect to different devices with the same name.
  // Set CoreDebugLevel to Info to view devices Bluetooth address and device names
  #ifdef USE_NAME
    connected = SerialBT.connect(slaveName);
    Serial.printf("Connecting to slave BT device named \"%s\"\n", slaveName.c_str());
 // #else
   // connected = SerialBT.connect(address);
    //erial.print("Connecting to slave BT device with MAC "); Serial.println(MACadd);
  #endif

  if(connected) {
    Serial.println("Connected Successfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
    }
  }
  // Disconnect() may take up to 10 secs max
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Successfully!");
  }
  // This would reconnect to the slaveName(will use address, if resolved) or address used with connect(slaveName/address).
  SerialBT.connect();
  if(connected) {
    Serial.println("Reconnected Successfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to reconnect. Make sure remote device is available and in range, then restart app.");
    }
  }
}

  void loop() {
    
  // read the potentiometer values and scale them to the range of 0
  int pot1Val = map(analogRead(12), 0, 4095, 0, 180);
  int pot2Val = map(analogRead(13), 0, 4095, 0, 180);
  int pot3Val = map(analogRead(2), 0, 4095, 0, 180);
  int pot4Val = map(analogRead(15), 0, 4095, 0, 180);

  Serial.print("POT 1 = ");
  Serial.println(pot1Val);
  Serial.print("POT 2 = ");
  Serial.println(pot2Val);
  Serial.print("POT 3 = ");
  Serial.println(pot3Val);
  Serial.print("POT 4 = ");
  Serial.println(pot4Val);

  // create an array to store the potentiometer val wues
  byte data[4];
  data[0] = pot1Val;
  data[1] = pot2Val;
  data[2] = pot3Val;
  data[3] = pot4Val;

  // send the potentiometer values over Bluetooth
  SerialBT.write(data, 4);
  

}
