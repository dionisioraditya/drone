#include "HardwareSerial.h"
#ifndef RANGESENSOR_H
#define RANGESENSOR_H
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#define SHUT_1 24
#define SHUT_2 53
#define SHUT_3 34
#define SHUT_4 6
#define SHUT_5 37

class RangeSensor{
  private:
    byte shut[5] = {SHUT_1, SHUT_2, SHUT_3, SHUT_4, SHUT_5};
    byte address[5]= {0x30, 0x31, 0x32, 0x33, 0x34};
    Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
    Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
    Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();
    Adafruit_VL53L0X lox4 = Adafruit_VL53L0X();
    Adafruit_VL53L0X lox5 = Adafruit_VL53L0X();
    VL53L0X_RangingMeasurementData_t measure;
  public:
    //RangeSensor(): shut []= {SHUT_1, SHUT_2, SHUT_3, SHUT_4, SHUT_5};
    //RangeSensor(): address[] = {0x30, 0x31, 0x32, 0x33, 0x34};
    void init() {
      Serial.begin(115200);
      Serial.println("Adafruit VL53L0X test");
      for (int i = 0; i < 5; i++) {
        pinMode(shut[i], OUTPUT);
        digitalWrite(shut[i], HIGH);
      }
      if (!lox1.begin(0x30)) {
          Serial.println(F("Failed to boot VL53L0X #1"));
          while (1);
      }
      if (!lox2.begin(0x31)) {
          Serial.println(F("Failed to boot VL53L0X #2"));
          while (1);
      }
      if (!lox3.begin(0x32)) {
          Serial.println(F("Failed to boot VL53L0X #3"));
          while (1);
      }
      if (!lox4.begin(0x33)) {
          Serial.println(F("Failed to boot VL53L0X #4"));
          while (1);
      }
      if (!lox5.begin(0x34)) {
          Serial.println(F("Failed to boot VL53L0X #5"));
          while (1);
      }
      lox1.setMeasurementTimingBudgetMicroSeconds(200000); 
      lox2.setMeasurementTimingBudgetMicroSeconds(200000); 
      lox3.setMeasurementTimingBudgetMicroSeconds(200000); 
      lox4.setMeasurementTimingBudgetMicroSeconds(200000); 
      lox5.setMeasurementTimingBudgetMicroSeconds(200000); 

      lox1.startRangeContinuous(200);
      lox2.startRangeContinuous(200);
      lox3.startRangeContinuous(200);
      lox4.startRangeContinuous(200);
      lox5.startRangeContinuous(200);
    }
    int getRange(byte sensor) {
      switch(sensor) {
        case 1:
          lox1.rangingTest(&measure, false);
          if(measure.RangeStatus !=4) {
            Serial.print("Sensor 1 Distance = ");
            Serial.println(measure.RangeMilliMeter);
            return measure.RangeMilliMeter;
          } else {
            Serial.println(" Sensor 1 out of range ");
          }
          break;
        case 2:
          lox2.rangingTest(&measure, false);
          if(measure.RangeStatus !=4) {
            Serial.print("Sensor 2 Distance = ");
            Serial.println(measure.RangeMilliMeter);
            return measure.RangeMilliMeter;
          }else {
            Serial.println(" Sensor 2 out of range ");
          }
          break;
        case 3:
          lox3.rangingTest(&measure, false);
          if(measure.RangeStatus !=4) {
            Serial.print("Sensor 3 Distance = ");
            Serial.println(measure.RangeMilliMeter);
            return measure.RangeMilliMeter;
          } else {
            Serial.println("Sensor 3 out of range ");
          }
          break;
        case 4:
          lox4.rangingTest(&measure, false);
          if(measure.RangeStatus !=4) {
            Serial.print("Sensor 4 Distance = ");
            Serial.println(measure.RangeMilliMeter);
            return measure.RangeMilliMeter;
          } else {
            Serial.println(" Sensor 4 out of range ");
          }
          break;
        case 5:
          lox5.rangingTest(&measure, false);
          if(measure.RangeStatus !=4) {
            Serial.print("Sensor 5 Distance = ");
            Serial.println(measure.RangeMilliMeter);
            return measure.RangeMilliMeter;
          } else {
            Serial.println(" Sensor 5 out of range ");
          }
          break;
      }
    }
    void turnOff() {
      for (int i = 0; i < 5; i++) {
        digitalWrite(shut[i], LOW);
      }
    }
    void turnOn() {
      for (int i = 0; i < 5; i++) {
        digitalWrite(shut[i], HIGH);
      }
    }

};
#endif