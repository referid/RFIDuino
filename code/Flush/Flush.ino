#include <SoftwareSerial.h>
#define BAUD 9600
#define INFO 0x01
#define ID 0x02
#define READ 0x03
#define WRITE 0x04
#define STANDY 0x10
#define TX_PIN 2
#define RX_PIN 3
#define SHORT 100
#define LONG 1000
#define BUFFER 4
#define MAX 32

char output[MAX];
SoftwareSerial rfid(TX_PIN, RX_PIN); // so the RFID can be read

void setup() {
  Serial.begin(BAUD);
  rfid.begin(BAUD);
}

void loop() {
  int temp;
  if (rfid.available()) {
    temp = rfid.write(0x00,HEX);
    Serial.println(temp);
  }

}
