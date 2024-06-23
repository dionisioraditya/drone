#include "OLEDDisplay.h"
#include "Controller.h"
OLEDDisplay oled;
Controller controller;
void setup() {
  Serial.begin(9600);
  oled.init();
  controller.init();
}
void loop() {
  oled.clearOled();
  controller.swLoop();
  if(controller.axis()== "FORWARD") {
    oled.print("FORWARD", 40, 40);
  } else if(controller.axis()=="BACKWARD") {
    oled.print("BACKWARD", 40, 40);
  } else if(controller.axis()=="RIGHT") {
    oled.print("RIGHT", 40, 40);
  } else if(controller.axis()=="LEFT") {
    oled.print("LEFT", 40, 40);
  } else if(controller.axis()=="FORWARD RIGHT") {
    oled.print("FORWARD RIGHT", 40, 40);
  } else if(controller.axis()=="FORWARD LEFT") {
    oled.print("FORWARD LEFT", 40, 40);
  } else if(controller.axis()=="BACKWARD RIGHT") {
    oled.print("BACKWARD RIGHT", 40, 40);
  } else if(controller.axis()=="BACKWARD LEFT") {
    oled.print("BACKWARD LEFT", 40, 40);
  } else {
    oled.print("HOVER", 40, 40);
  }

  oled.displayOled();
}