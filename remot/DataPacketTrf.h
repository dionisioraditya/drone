#ifndef DATAPACKETTRF_H
#define DATAPACKETTRF_H
// data receive container 
struct DataPacketTrf {
  char joystick[15];
  char switchJoystik1[15];
  char switchJoystik2[15];
  byte toggleSwitch1;
  byte toggleSwitch2;
  int pot1;
  int pot2;
};

#endif