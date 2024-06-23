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

class Controller {
  private:
    ezButton button1;
    ezButton button2;
    int xValue1; // To store value of the X axis
    int yValue1; // To store value of the Y axis
    int bValue1; // To store value of the button
    int xValue2; // To store value of the X axis
    int yValue2; // To store value of the Y axis
    int bValue2; // To store value of the button

  public:
    Controller() : button1(SW_PIN), button2(SW_PIN2) {}

    void init() {
      button1.setDebounceTime(50);
      button2.setDebounceTime(50);
    }

    void swLoop() {
      button1.loop();
      button2.loop();
    }

    String axis() {
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
    void SerialPrint() {
      Serial.print(yValue1);
    }
};

#endif