#ifndef PIDController_H
#define PIDController_H
class PIDController {
  private:
    float Kp = 1.0;
    float Ki = 0.01;
    float Kd = 0.05;

    float pitch_error, roll_error, yaw_error;
    float pitch_integral = 0, roll_integral = 0, yaw_integral = 0;
    float pitch_previous_error = 0, roll_previous_error = 0, yaw_previous_error = 0;
    float dt = 0.05;  // Time step
  public:
    void updatePID(
      float pitch_setpoint, 
      float roll_setpoint, 
      float yaw_setpoint, 
      float RateYaw, 
      float RatePitch, 
      float RateRoll
      ) {
      pitch_error = pitch_setpoint - RatePitch;
      pitch_integral += pitch_error * dt;
      float pitch_derivative = (pitch_error - pitch_previous_error) / dt;
      float pitch_output = Kp * pitch_error + Ki * pitch_integral + Kd * pitch_derivative;
      pitch_previous_error = pitch_error;

      // Calculate roll PID (proses sama untuk roll dan yaw)
      roll_error = roll_setpoint - RateRoll;
      roll_integral += roll_error * dt;
      float roll_derivative = (roll_error - roll_previous_error) / dt;
      float roll_output = Kp * roll_error + Ki * roll_integral + Kd * roll_derivative;
      roll_previous_error = roll_error;

      // Calculate yaw PID (optional, tergantung apakah input remote mengatur yaw)
      yaw_error = yaw_setpoint - RateYaw;
      yaw_integral += yaw_error * dt;
      float yaw_derivative = (yaw_error - yaw_previous_error) / dt;
      float yaw_output = Kp * yaw_error + Ki * yaw_integral + Kd * yaw_derivative;
      yaw_previous_error = yaw_error;

      // 
    }
};
#endif