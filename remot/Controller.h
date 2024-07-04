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
#define POT1 A6
#define POT2 A7
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
      this->TSW_State1 = 0;
      this->TSW_State2 = 0;
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
      if (yValue1 > 600 && xValue2 > 400 && xValue2 < 600) {
        return "FORWARD";
      } else if (yValue1 < 500 && xValue2 > 400 && xValue2 < 600) {
        return "BACKWARD";
      } else if (xValue2 > 500 && yValue1 > 400 && yValue1 < 600) {
        return "RIGHT";
      } else if (xValue2 < 400 && yValue1 > 400 && yValue1 < 600) {
        return "LEFT";
      } else if (yValue1 > 600 && xValue2 > 600) {
        return "FORWARD RIGHT";
      } else if (yValue1 > 600 && xValue2 < 400) {
        return "FORWARD LEFT";
      } else if (yValue1 < 400 && xValue2 > 600) {
        return "BACKWARD RIGHT";
      } else if (yValue1 < 400 && xValue2 < 400) {
        return "BACKWARD LEFT";
      } else {
        return "HOVER";
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
    
    void SerialPrint() {
      Serial.print(yValue1);
    }
    byte tsw1Value() {
      this->TSW_State1 = digitalRead(TSW_PIN1);
      return this->TSW_State1 = 1;
    }
    byte tsw2Value() {
      this->TSW_State2 = digitalRead(TSW_PIN2);
      return this->TSW_State2;
    }
    int pot1() {
      this->pot1Value = digitalRead(POT1);
      return this->pot1Value;
    }
    int pot2() {
      this->pot2Value = digitalRead(POT2);
      return this->pot2Value;
    }
};

#endif