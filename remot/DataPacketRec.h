#ifndef DATAPACKETREC_H
#define DATAPACKETREC_H
// data receive container 
struct DataPacketRec {
  int8_t altitude;
  int8_t xAxisTilt;
  int8_t yAxisTilt;
  char strValue[20];
};

#endif