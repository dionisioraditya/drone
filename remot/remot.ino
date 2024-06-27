#include "OLEDDisplay.h"
#include "Controller.h"
#include "Radio.h"
#include "DataPacket.h"
OLEDDisplay oled;
Controller controller;
Radio radioTrf, radioRec;
DataPacket dataReceive;
void setup() {
  Serial.begin(9600);
  oled.init();
  controller.init();
  radioTrf.initTransfer();
  radioRec.initReceive();
}
void loop() {
  if(controller.tsw1Value()==1) {
    oled.clearOled();
    controller.swLoop();
    radioTrf.transferInt(controller.pot1());
    if(controller.axis()== "FORWARD") {
      oled.print("FORWARD", 40, 40);
      radioTrf.transfer("FORWARD");
    } 
    else if(controller.axis()=="BACKWARD") {
      oled.print("BACKWARD", 40, 40);
      radioTrf.transfer("BACKWARD");
    } 
    else if(controller.axis()=="RIGHT") {
      oled.print("RIGHT", 40, 40);
      radioTrf.transfer("RIGHT");
    } 
    else if(controller.axis()=="LEFT") {
      oled.print("LEFT", 40, 40);
      radioTrf.transfer("LEFT");
    } 
    else if(controller.axis()=="FORWARD RIGHT") {
      oled.print("FORWARD RIGHT", 40, 40);
      radioTrf.transfer("FORWARD RIGHT");
    } 
    else if(controller.axis()=="FORWARD LEFT") {
      oled.print("FORWARD LEFT", 40, 40);
      radioTrf.transfer("FORWARD LEFT");
    } 
    else if(controller.axis()=="BACKWARD RIGHT") {
      oled.print("BACKWARD RIGHT", 40, 40);
      radioTrf.transfer("BACKWARD RIGHT");
    } 
    else if(controller.axis()=="BACKWARD LEFT") {
      oled.print("BACKWARD LEFT", 40, 40);
      radioTrf.transfer("BACKWARD LEFT");
    } 
    else {
      oled.print("HOVER", 40, 40);
      radioTrf.transfer("HOVER");
    }
    if(controller.swState(1)==1) {
      oled.print("SW1 ON", 0, 0);
      radioTrf.transfer("SW1 ON");
    } else {
      oled.print("SW1 OFF", 0, 0);
      radioTrf.transfer("SW1 OFF");
    }
    if(controller.swState(2)==1) {
      oled.print("SW2 ON", 60, 0);
      radioTrf.transfer("SW2 ON");
    } else {
      oled.print("SW2 OFF", 60, 0);
      radioTrf.transfer("SW2 OFF");
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