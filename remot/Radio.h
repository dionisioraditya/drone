#ifndef RADIO_H
#define RADIO_H

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 10
#define CNS 8

class Radio {
  private:
    RF24 radio;
    const byte address[6] = { '0', '0', '0', '0', '1' };
    
  public:
    Radio() : radio(CE, CNS) {}

    void init() {
      radio.begin();
      radio.openWritingPipe(address);
      radio.setPALevel(RF24_PA_MIN);
      radio.startListening();
    }

    void transfer(const char txt[]) {
      radio.write(&txt, sizeof(txt)+1);
    }
    String receive(){
      if(radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        return text;
      }
    }
};

#endif
