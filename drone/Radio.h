#ifndef RADIO_H
#define RADIO_H

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "DataPacketRec.h"
#include "DataPacketTrf.h"
#define CE1 22
#define CSN1 23
#define CE2 35
#define CSN2 33

class Radio{
  private:
    RF24 radioReceiver;
    RF24 radioTransmiter;
    const byte address1[6] = { 'T', 'X', 'A', 'A', 'A' };
    const byte address2[6] = { '0', '0', '0', '0', '1' };
  public:
    Radio() : radioReceiver(CE1, CSN1), radioTransmiter(CE2, CSN2){}
    void initTransfer() {
      radioTransmiter.begin();
      //radioTransmiter.setChannel(76); // Set the channel to 76
      radioTransmiter.openWritingPipe(address2);
      radioTransmiter.setPALevel(RF24_PA_MIN);
      radioTransmiter.stopListening();
      Serial.println("Transmitter initialized.");
    }
    void initReceive() {
      radioReceiver.begin();
      radioReceiver.openReadingPipe(0, address1);
      radioReceiver.setPALevel(RF24_PA_MIN);
      radioReceiver.startListening();
    }
    void transfer(DataPacketTrf& data) {
      //Serial.println("Attempting to send data...");
      radioTransmiter.write(&data, sizeof(data));
      if (radioTransmiter.write(&data, sizeof(data))) {
        Serial.print("   Data sent successfully.  ");
      } else {
        Serial.print("   Failed to send data.  ");
      }
    }
    _Bool receive(DataPacketRec& data) {
      if(radioReceiver.available()) {
        radioReceiver.read(&data, sizeof(data));
        return true;
      }
      return false;
    }

};
#endif