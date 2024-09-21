#ifndef GYRO_H
#define GYRO_H
#include <Arduino.h>
#include <Wire.h>
class Gyro {
  private:
    float RateRoll;
    float RatePitch;
    float RateYaw;
    float RateCalibrationRoll;
    float RateCalibrationPitch;
    float RateCalibrationYaw;
    int RateCalibrationNumber;
    void gyro_signal (void) {
      Wire.beginTransmission(0x68);
      // Switch on the low pass filter
      Wire.write(0x1A);
      Wire.write(0x05);
      Wire.endTransmission();
      // set the sensitivity scale factor
      Wire.beginTransmission(0x68);
      Wire.write(0x1B);
      Wire.write(0x8);
      Wire.endTransmission();
      // Acces register storing gyro measurements
      Wire.beginTransmission(0x68);
      Wire.write(0x43);
      Wire.endTransmission();
      Wire.requestFrom(0x68,6);

      // read the gyro measurements around the x axis
      int16_t GyroX = Wire.read()<< 8| Wire.read();
      int16_t GyroY = Wire.read()<< 8| Wire.read();
      int16_t GyroZ = Wire.read()<< 8| Wire.read();

      // convert the measurement units to °/ s
      RateRoll = (float) GyroX/ 65.5;
      RatePitch = (float) GyroY/ 65.5;
      RateYaw = (float) GyroZ/ 65.5;
    }
  public:
    void init() {
      Wire.setClock(400000);
      Wire.begin();
      delay(250);

      // set the gyro in power mode
      Wire.beginTransmission(0x68);
      Wire.write(0x6B);
      Wire.write(0x00);
      Wire.endTransmission();

      // perform the calibration measurements
      for(RateCalibrationNumber = 0; RateCalibrationNumber < 2000; RateCalibrationNumber++) {
        gyro_signal();
        RateCalibrationRoll += RateRoll;
        RateCalibrationPitch += RatePitch;
        RateCalibrationYaw += RateYaw;
        delay(1);
      }
      // Calculate the calibration values
      RateCalibrationRoll/=2000;
      RateCalibrationPitch/=2000;
      RateCalibrationYaw/=2000;
    }
    void runGyro() {
      gyro_signal();
    }
    float rateRoll() {
      return RateRoll -= RateCalibrationRoll;
    }
    float ratePitch() {
      return RatePitch -= RateCalibrationPitch;
    }
    float rateYaw() {
      return RateYaw -= RateCalibrationYaw;
    }
};
#endif