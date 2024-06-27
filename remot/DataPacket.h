#ifndef DATAPACKET_H
#define DATAPACKET_H
// data receive container 
struct DataPacket {
  int altitude;
  int xAxisTilt;
  int yAxisTilt;
  char strValue[20];
};

#endif