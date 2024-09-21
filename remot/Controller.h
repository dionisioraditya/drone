#include "HardwareSerial.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ezButton.h>
#include <Arduino.h>

#define VRX_PIN1  A1 // Arduino pin connected to VRX pin
#define VRY_PIN1  A0 // Arduino pin connected to VRY pin
#define VRX_PIN2  A3 // Arduino pin connected to VRX pin
#define VRY_PIN2  A2 // Arduino pin connected to VRY pin
#define SW_PIN    2  // Arduino pin connected to SW  pin
#define SW_PIN2   3
#define TSW_PIN1 4
#define TSW_PIN2 5
#define POT1 A7
#define POT2 A6
class Controller {
  private:
    ezButton button1;
    ezButton button2;
    int xValue1; // To store value of the X axis
    int yValue1; // To store value of the Y axis
    byte bValue1; // To store value of the button
    int xValue2; // To store value of the X axis
    int yValue2; // To store value of the Y axis
    byte bValue2; // To store value of the button
    byte TSW_State1;
    byte TSW_State2;
    int pot1Value;
    int pot2Value;
  public:
    Controller() : button1(SW_PIN), button2(SW_PIN2) {}

    void init() {
      button1.setDebounceTime(50);
      button2.setDebounceTime(50);
      pinMode(TSW_PIN1, INPUT_PULLUP);
      pinMode(TSW_PIN2, INPUT_PULLUP);
      TSW_State1 = 0;
      TSW_State2 = 0;
    }

    void swLoop() {
      button1.loop();
      button2.loop();
    }
    const char* axis() {
      xValue1 = analogRead(VRX_PIN1);
      yValue1 = analogRead(VRY_PIN1);
      bValue1 = button1.getState();

      xValue2 = analogRead(VRX_PIN2);
      yValue2 = analogRead(VRY_PIN2);
      bValue2 = button2.getState();
      if (yValue1 > 600 && xValue1 > 400 && xValue1 < 600) {
        return "FORWARD";
      } else if (yValue1 < 500 && xValue1 > 400 && xValue1 < 600) {
        return "BACKWARD";
      } else if (xValue1 > 520 && yValue1 > 400 && yValue1 < 600) {
        return "RIGHT";
      } else if (xValue1 < 500 && yValue1 > 400 && yValue1 < 600) {
        return "LEFT";
      } else if (yValue1 > 600 && xValue1 > 600) {
        return "FORWARD RIGHT";
      } else if (yValue1 > 600 && xValue1 < 400) {
        return "FORWARD LEFT";
      } else if (yValue1 < 400 && xValue1 > 600) {
        return "BACKWARD RIGHT";
      } else if (yValue1 < 400 && xValue1 < 400) {
        return "BACKWARD LEFT";
      } else {
        return "HOVER";
      }
    }
    int getJoyStick2(const char* axis) {
      if(axis == "x") {
        return xValue2;
      } 
      if (axis == "y") {
        return yValue2;
      }
    }
    int swState(int buttonIndex) {
      if(buttonIndex ==1) {
        return bValue1;
      } else if(buttonIndex==2) {
        return bValue2;
      } else {
        return 0;
      }
    }
    int  printSerial() {
      return xValue1;
    }
    byte tsw1Value() {
      TSW_State1 = digitalRead(TSW_PIN1);
      return TSW_State1;
    }
    byte tsw2Value() {
      TSW_State2 = digitalRead(TSW_PIN2);
      return TSW_State2;
    }
    int pot1() {
      pot1Value = analogRead(POT1);
      return pot1Value;
    }
    int pot2() {
      pot2Value = analogRead(POT2);
      return pot2Value;
    }
};

#endif