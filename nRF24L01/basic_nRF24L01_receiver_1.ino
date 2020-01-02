// basic nRFL01 receiver

// Basic Arduino Connections
// MOSI (pin 6) -> 11
// MISO (pin 7) -> 12
// SCK (pin 5) -> 13
// Vcc -> 3VDC
// other two connections, CE -> 9, and CSN -> 10, are defined below

//#include <SPI.h>
// this is the TMRh20 library
// had issues with adding it the normal way so had to download the ZIP file and add it that way
#include <nRF24L01.h>
#include <RF24.h>

// setup the receiver
RF24 radio(9, 10); // CE, CSN

// set the address, needs to be the same on both
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  // start the connection
  radio.begin();
  // setup the receiver
  radio.openReadingPipe(0, address);
  // set the power level
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  //Serial.println("start radio loop");
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  delay(250);
}
