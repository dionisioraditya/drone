#ifndef DATAPACKET_H
#define DATAPACKET_H

struct DataPacket {
  int altitude;
  int xAxisTilt;
  int yAxisTilt;
  char strValue[20];
};

#endif