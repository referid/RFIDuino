#include <SoftwareSerial.h>
#define BAUD 9600
#define INFO 0x01
#define SERIAL 0x02
#define READ 0x03
#define WRITE 0x04
#define STANDY 0x10
#define TX_PIN 2
#define RX_PIN 3
#define SHORT 100
#define LONG 1000
#define BUFFER 4
#define SPACE 1
#define MAX 32

char output[MAX];
SoftwareSerial rfid(TX_PIN, RX_PIN); // so the RFID can be read

void setup() {
  Serial.begin(BAUD);
  rfid.begin(BAUD);
}

void loop() {
  int temp[BUFFER];
  if (rfid.available()) {
    Serial.println("-------");
    rfid.write(0xAB); rfid.write(0x02); rfid.write(0x02);
    delay(SHORT);
    for (int i = 0; i < BUFFER; i++) {
      temp[i] = rfid.read();
    }
    sprintf(output, "{'data':%d,%d,%d,%d}", temp[0],temp[1],temp[2],temp[3]);
    Serial.println(output);
    
    rfid.write(0xAB);
    rfid.write(0x0A);
    rfid.write(0x03);
    rfid.write(byte(0));
    delay(SHORT);
    for (int i = 0; i < BUFFER; i++) {
      temp[i] = rfid.read();
    }
    sprintf(output, "{'data':%d,%d,%d,%d}", temp[0],temp[1],temp[2],temp[3]);
    Serial.println(output);
  }
  delay(LONG); // check for card every on interval
}
