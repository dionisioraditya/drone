#ifndef DATAPACKETTRF_H
#define DATAPACKETTRF_H
// data receive container 
struct DataPacketTrf {
  char joystick1[15];
  int joystick2;
  int pot1;
  int pot2;
  byte toggleSwitch;
  char switchJoystik1[15];
  char switchJoystik2[15];
};

#endif