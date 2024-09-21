#ifndef MPU6050_H
#define MPU6050_H
#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

class Mpu6050 {
  private:
  MPU6050 sensor;
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  byte x;
  byte y;
  byte z;
  public: 

  void init() {
    Wire.begin();
    sensor.initialize();
  }
  void getMotion(){
    sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  }
  byte X() {
    return x = map(ax, -17000, 17000, 0, 255 );
  } 
  byte Y() {
    return y = map(ay, -17000, 17000, 0, 255); 
  }
  byte Z() {
    return z = map(az, -17000, 17000, 0, 255);
  }
};
#endif