#ifndef RADIO_H
#define RADIO_H

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 7
#define CNS 8
#define CE2 10
#define CNS2 6

class Radio {
  private:
    RF24 radio1;
    RF24 radio2;
    const byte address1[6] = { 'T', 'X', 'A', 'A', 'A' };
    const byte address2[6] = { 'R', 'X', 'A', 'A', 'A' };
  public:
    Radio() : radio1(CE, CNS), radio2(CE2, CNS2) {}

    void initTransfer() {
      radio1.begin();
      radio1.openWritingPipe(address1);
      radio1.setPALevel(RF24_PA_MIN);
      radio1.stopListening();
    }
    void initReceive() {
      radio2.begin();
      radio2.openWritingPipe(address2);
      radio2.setPALevel(RF24_PA_MIN);
      radio2.startListening();
    }
    void transfer(const char txt[]) {
      radio1.write(&txt, sizeof(txt)+1);
    }
    String receive(){
      if(radio2.available()) {
        char text[32] = "";
        radio2.read(&text, sizeof(text));
        return text;
      }
    }
};

#endif
