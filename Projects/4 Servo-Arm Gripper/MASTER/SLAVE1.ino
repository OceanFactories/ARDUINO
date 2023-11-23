#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>
#include "BluetoothSerial.h"

//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
//const char *pin = "1234"; // Change this to more secure PIN.

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
  servo1.attach(12);
  servo2.attach(13);
  servo3.attach(2);
  servo4.attach(15);
}

void loop(){
  if (SerialBT.available()){
    // Read all the available bytes from SerialBT
    byte data[4];
    int bytesRead = SerialBT.readBytes(data, 4);

    // Check that we have read the correct number of bytes
    if (bytesRead == 4) {
      // Extract the potentiometer values from the data array
      int pot1Val = data[0];
      int pot2Val = data[1];
      int pot3Val = data[2];
      int pot4Val = data[3];

      // Print the potentiometer values to the serial monitor
      Serial.print("pot 1 = ");
      Serial.println(pot1Val); 
      Serial.print("pot 2 = ");
      Serial.println(pot2Val);
      Serial.print("pot 3 = ");
      Serial.println(pot3Val);
      Serial.print("pot 4 = ");
      Serial.println(pot4Val);



      // Update the servo positions based on the potentiometer values
        servo1.write(pot1Val);
        servo2.write(pot2Val);
        servo3.write(pot3Val);
        servo4.write(pot4Val);
     
    }}}
