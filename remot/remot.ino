#include "OLEDDisplay.h"
#include "Controller.h"
#include "Radio.h"
#include "DataPacketRec.h"
OLEDDisplay oled;
Controller controller;
Radio radioTrf, radioRec;
DataPacketRec dataReceive;
DataPacketTrf dataTrf;
void setup() {
  Serial.begin(9600);
  oled.init();
  controller.init();
  radioTrf.initTransfer();
  radioRec.initReceive();
}
void loop() {
  
  if(controller.tsw1Value()==1) {
    dataTrf.toggleSwitch2 = controller.tsw2Value();
    radioTrf.transfer(dataTrf);
    Serial.println(dataTrf.joystick);
    oled.clearOled();
    controller.swLoop();
    dataTrf.pot1 = controller.pot1();
    radioTrf.transfer(dataTrf);
    if(controller.axis()== "FORWARD") {
      oled.print("FORWARD", 40, 40);
      strcpy(dataTrf.joystick, "FORWARD");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD") {
      oled.print("BACKWARD", 40, 40);
      strcpy(dataTrf.joystick, "BACKWARD");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="RIGHT") {
      oled.print("RIGHT", 40, 40);
      strcpy(dataTrf.joystick, "RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="LEFT") {
      oled.print("LEFT", 40, 40);
      strcpy(dataTrf.joystick, "LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="FORWARD RIGHT") {
      oled.print("FORWARD RIGHT", 40, 40);
      strcpy(dataTrf.joystick, "FORWARD RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="FORWARD LEFT") {
      oled.print("FORWARD LEFT", 40, 40);
      strcpy(dataTrf.joystick, "FORWARD LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD RIGHT") {
      oled.print("BACKWARD RIGHT", 40, 40);
      strcpy(dataTrf.joystick, "BACKWARD RIGHT");
      radioTrf.transfer(dataTrf);
    } 
    else if(controller.axis()=="BACKWARD LEFT") {
      oled.print("BACKWARD LEFT", 40, 40);
      strcpy(dataTrf.joystick, "BACKWARD LEFT");
      radioTrf.transfer(dataTrf);
    } 
    else {
      oled.print("HOVER", 40, 40);
      strcpy(dataTrf.joystick, "HOVER");
      radioTrf.transfer(dataTrf);
    }
    if(controller.swState(1)==1) {
      oled.print("SW1 ON", 0, 0);
      strcpy(dataTrf.switchJoystik1, "SW1 ON");
      radioTrf.transfer(dataTrf);
    } else {
      oled.print("SW1 OFF", 0, 0);
      strcpy(dataTrf.switchJoystik1, "SW1 OFF");
      radioTrf.transfer(dataTrf);
    }
    if(controller.swState(2)==1) {
      oled.print("SW2 ON", 60, 0);
      strcpy(dataTrf.switchJoystik2, "SW2 ON");
      radioTrf.transfer(dataTrf);
    } else {
      oled.print("SW2 OFF", 60, 0);
      strcpy(dataTrf.switchJoystik2, "SW2 OFF");
      radioTrf.transfer(dataTrf);
    }
    oled.displayOled();
  } else {
    oled.clearOled();
    if(radioRec.receive(dataReceive)==true) {
      oled.print("Altitude: "+dataReceive.altitude, 0, 0);
      oled.print("Y tilt: "+dataReceive.yAxisTilt, 0, 10);
      oled.print("X tilt: "+dataReceive.xAxisTilt, 40, 10);
    }
    oled.displayOled();
  }
}