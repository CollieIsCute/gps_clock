#include <Serial.h>
#include <TinyGPSPlus.h>

const unsigned int gps_rx = 17, gps_tx = 16;
const unsigned int Baudrate = 9600;
UART gps_uart(gps_tx, gps_rx );
TinyGPSPlus gps;
  char buf[50];

void setup(){
  Serial.begin(Baudrate);
  gps_uart.begin(Baudrate);
}

void loop(){
  while (gps_uart.available() > 0) {
    // 讀取資料
    char c = gps_uart.read();
    // 將資料傳遞給 gps 物件
    gps.encode(c);
  }
  Serial.print("Satellites number :");
  Serial.println(gps.satellites.value());
  // 取得時間資訊
  sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", gps.date.year(), gps.date.month(), gps.date.day(),(gps.time.hour()+8)%24,gps.time.minute(),gps.time.second());
  Serial.println(buf);
  sleep_ms(100);
}
