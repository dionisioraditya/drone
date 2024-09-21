//#include "Mpu6050.h"
#include "Gyro.h"
#include "RangeSensor.h"
#include "Radio.h"
#include "DataPacketRec.h"
#include "DataPacketTrf.h"
//Mpu6050 mpu;
Gyro gyro;
RangeSensor rangeSensor;
Radio radioReceiver;
Radio radioTransfer;
DataPacketRec dataReceive;
DataPacketTrf dataTransfer;
void setup() { 
  Serial.begin(9600);
  //mpu.init();
  //rangeSensor.init();
  radioTransfer.initTransfer();
  radioReceiver.initReceive();
  gyro.init();
}
void loop() {
  gyro.runGyro();
  dataTransfer.altitude = 10;
  radioTransfer.transfer(dataTransfer);
  if(radioReceiver.receive(dataReceive) == true) {
    Serial.print("Joystick1: ");
    Serial.print(dataReceive.joystick1);
    Serial.print("   Joystick2: ");
    Serial.print(dataReceive.joystick2);
    Serial.print("   Pot1: ");
    Serial.print(dataReceive.pot1);
    Serial.print("   Pot2: ");
    Serial.print(dataReceive.pot2);
    Serial.print("   Toggle sw: ");
    Serial.print(dataReceive.toggleSwitch);
    Serial.println("");
  }
  // Serial.print("Data: ");
  // Serial.println(dataReceive.joystick1);
}
