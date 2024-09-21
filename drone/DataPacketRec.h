#ifndef DATAPACKETREC_H
#define DATAPACKETREC_H

struct DataPacketRec{
  char joystick1[15];
  int joystick2;
  int pot1;
  int pot2;
  byte toggleSwitch;
  char switchJoystik1[15];
  char switchJoystik2[15];
};
#endif