#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

class OLEDDisplay {
  private:
    Adafruit_SSD1306 display;

  public:
    OLEDDisplay() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

    void init() {
      if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
      }
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
    }
    void clearOled() {
      display.clearDisplay();
    }
    void println(String str, int16_t x, int16_t y) {
      display.setCursor(x, y);
      display.println(str);
    }
    void print(String str, int16_t x, int16_t y) {
      display.setCursor(x, y);
      display.print(str);
    }
    void displayOled() {
      display.display();
    }
};

#endif