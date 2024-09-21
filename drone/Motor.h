#ifndef Motor_H
#define Motor_H
#include <Arduino.h>
#define MOTORDEPANKIRI 46
#define MOTORDEPANKANAN 13
#define MOTORBELAKANGKIRI 44
#define MOTORBELAKANGKANAN 5
class Motor{
  private:
    float motor1_speed;
    float motor2_speed;
    float motor3_speed;
    float motor4_speed;
  public:
    void adjustMotorSpeed(float pitch_output, float roll_output, float yaw_output) {
      // Motor1 (depan kiri), Motor2 (depan kanan), Motor3 (belakang kiri), Motor4 (belakang kanan)
      
      float motor1_speed = base_throttle + pitch_output + roll_output - yaw_output;
      float motor2_speed = base_throttle + pitch_output - roll_output + yaw_output;
      float motor3_speed = base_throttle - pitch_output - roll_output - yaw_output;
      float motor4_speed = base_throttle - pitch_output + roll_output + yaw_output;
      
      // Sesuaikan PWM ke motor untuk mengontrol kecepatan
      analogWrite(MOTORDEPANKIRI, constrain(motor1_speed, 0, 255));
      analogWrite(MOTORDEPANKANAN, constrain(motor2_speed, 0, 255));
      analogWrite(MOTORBELAKANGKIRI, constrain(motor3_speed, 0, 255));
      analogWrite(MOTORBELAKANGKANAN, constrain(motor4_speed, 0, 255));
    }
};
#endif