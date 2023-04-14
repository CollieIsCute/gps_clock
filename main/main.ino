#include <TinyGPSPlus.h>
#include <SerialPIO.h>
// #include <TFT_eSPI.h>
// #include <SPI.h>
// #include "Free_Fonts.h" // Include the header file attached to this sketch

const unsigned int gps_rx = 17, gps_tx = 16;
const unsigned int Baudrate = 9600;
SerialPIO gps_uart(gps_tx, gps_rx, 300);
TinyGPSPlus gps = TinyGPSPlus();
char buf[50];
// TFT_eSPI tft = TFT_eSPI();
// int cnt = 0;

void setup(){
  Serial.begin(Baudrate);
  gps_uart.begin(Baudrate);
}

void loop(){
  while(gps_uart.available())
    gps.encode(gps_uart.read());
}

void setup1(){
  Serial.begin(Baudrate);
  // tft.begin(Baudrate);
  // tft.setRotation(1);
}

void loop1(){
  sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", gps.date.year(), gps.date.month(), gps.date.day(),(gps.time.hour()+8)%24,gps.time.minute(),gps.time.second());
  Serial.print("Satellites number :");
  Serial.println(gps.satellites.value());
  // 取得時間資訊
  Serial.println(buf);
  /*if(strcmp(buf, new_buf)){
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    int xpos = tft.width() / 2; // Half the screen width
    int ypos = 50;
    tft.setFreeFont(FSB24);
    tft.drawString(new_buf, xpos, ypos, GFXFF);
    strcpy(buf, new_buf);
  }*/
  sleep_ms(300);
}