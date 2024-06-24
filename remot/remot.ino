#include "OLEDDisplay.h"
#include "Controller.h"
#include "Radio.h"
OLEDDisplay oled;
Controller controller;
Radio radio;
void setup() {
  Serial.begin(9600);
  oled.init();
  controller.init();
  radio.initTransfer();
}
void loop() {
  oled.clearOled();
  controller.swLoop();
  if(controller.axis()== "FORWARD") {
    oled.print("FORWARD", 40, 40);
    radio.transfer("FORWARD");
  } 
  else if(controller.axis()=="BACKWARD") {
    oled.print("BACKWARD", 40, 40);
    radio.transfer("BACKWARD");
  } 
  else if(controller.axis()=="RIGHT") {
    oled.print("RIGHT", 40, 40);
    radio.transfer("RIGHT");
  } 
  else if(controller.axis()=="LEFT") {
    oled.print("LEFT", 40, 40);
    radio.transfer("LEFT");
  } 
  else if(controller.axis()=="FORWARD RIGHT") {
    oled.print("FORWARD RIGHT", 40, 40);
    radio.transfer("FORWARD RIGHT");
  } 
  else if(controller.axis()=="FORWARD LEFT") {
    oled.print("FORWARD LEFT", 40, 40);
    radio.transfer("FORWARD LEFT");
  } 
  else if(controller.axis()=="BACKWARD RIGHT") {
    oled.print("BACKWARD RIGHT", 40, 40);
    radio.transfer("BACKWARD RIGHT");
  } 
  else if(controller.axis()=="BACKWARD LEFT") {
    oled.print("BACKWARD LEFT", 40, 40);
    radio.transfer("BACKWARD LEFT");
  } 
  else {
    oled.print("HOVER", 40, 40);
    radio.transfer("HOVER");
  }
  if(controller.swState(1)==1) {
    oled.print("SW1 ON", 0, 0);
    radio.transfer("SW1 ON");
  } else {
    oled.print("SW1 OFF", 0, 0);
    radio.transfer("SW1 OFF");
  }
  if(controller.swState(2)==1) {
    oled.print("SW2 ON", 60, 0);
    radio.transfer("SW2 ON");
  } else {
    oled.print("SW2 OFF", 60, 0);
    radio.transfer("SW2 OFF");
  }
  oled.displayOled();
}