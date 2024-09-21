#include "OLEDDisplay.h"
#include "Controller.h"
#include "Radio.h"
#include "DataPacketRec.h"
//OLEDDisplay oled;
Controller controller;
Radio radioTrf, radioRec;
DataPacketRec dataReceive;
DataPacketTrf dataTrf;
void setup() {
  Serial.begin(9600);
  //oled.init();
  controller.init();
  radioTrf.initTransfer();
  radioRec.initReceive();
}
void loop() {
  
  if(controller.tsw1Value()==1) {
    //Serial.println(controller.printSerial());
    //Serial.println(dataTrf.pot2);
    if(radioRec.receive(dataReceive) == true) {
      Serial.print("Data: ");
      Serial.println(dataReceive.altitude);
    }
    // Serial.print("Data: ");
    // Serial.println(dataReceive.altitude);
   //oled.clearOled();
    controller.swLoop();
    dataTrf.pot2 = controller.pot2();
    dataTrf.pot1 = controller.pot1();
    dataTrf.toggleSwitch = controller.tsw2Value();
    dataTrf.joystick2 = controller.getJoyStick2("y");
    radioTrf.transfer(dataTrf);
    if(controller.axis()== "FORWARD") {
      //oled.print("FORWARD", 40, 40);
      strcpy(dataTrf.joystick1, "FORWARD");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD") {
      //oled.print("BACKWARD", 40, 40);
      strcpy(dataTrf.joystick1, "BACKWARD");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="RIGHT") {
      //oled.print("RIGHT", 40, 40);
      strcpy(dataTrf.joystick1, "RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="LEFT") {
      //oled.print("LEFT", 40, 40);
      strcpy(dataTrf.joystick1, "LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="FORWARD RIGHT") {
      //oled.print("FORWARD RIGHT", 40, 40);
      strcpy(dataTrf.joystick1, "FORWARD RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="FORWARD LEFT") {
      //oled.print("FORWARD LEFT", 40, 40);
      strcpy(dataTrf.joystick1, "FORWARD LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD RIGHT") {
      //oled.print("BACKWARD RIGHT", 40, 40);
      strcpy(dataTrf.joystick1, "BACKWARD RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD LEFT") {
      //oled.print("BACKWARD LEFT", 40, 40);
      strcpy(dataTrf.joystick1, "BACKWARD LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else {
      //oled.print("HOVER", 40, 40);
      strcpy(dataTrf.joystick1, "HOVER");
      radioTrf.transfer(dataTrf);
    }
    if(controller.swState(1)==1) {
      //oled.print("SW1 ON", 0, 0);
      strcpy(dataTrf.switchJoystik1, "SW1 ON");
      radioTrf.transfer(dataTrf);
    } else {
      //oled.print("SW1 OFF", 0, 0);
      strcpy(dataTrf.switchJoystik1, "SW1 OFF");
      radioTrf.transfer(dataTrf);
    }
    if(controller.swState(2)==1) {
      //oled.print("SW2 ON", 60, 0);
      strcpy(dataTrf.switchJoystik2, "SW2 ON");
      radioTrf.transfer(dataTrf);
    } else {
      //oled.print("SW2 OFF", 60, 0);
      strcpy(dataTrf.switchJoystik2, "SW2 OFF");
      radioTrf.transfer(dataTrf);
    }
    //oled.displayOled();
  } else {
    //oled.clearOled();
    if(radioRec.receive(dataReceive)==true) {
      //oled.print("Altitude: "+dataReceive.altitude, 0, 0);
    }
    //oled.displayOled();
  }
}