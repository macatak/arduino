// basic nRF24L01 transmitter

// Basic Arduino Connections
// MOSI (pin 6) -> 11
// MISO (pin 7) -> 12
// SCK (pin 5) -> 13
// Vcc -> 3VDC
// other two connections, CE -> 9, and CSN -> 10,  are defined below

// includes
// this is the TMRh20 library
#include "nRF24L01.h"
#include "RF24.h"
// not sure if we need this but they all have it
//#include <SPI.h>

// declare a radio object
// syntax radio(CE pin, CSN pin)
// pin 9 -> CE, pin 10 -> CSN
RF24 radio(9,10);

// set the address, needs to be the same on both
const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  // start the connection
  radio.begin();
  // set level
  radio.setPALevel(RF24_PA_MIN);
  // transmit on the address
  radio.openWritingPipe(address);
  // not sure if we need this
  //radio.stopListening();
  // for printing
  Serial.begin(9600);
}

void loop() {
  // setup some messages
  const char msg1[] = "message 1";
  const char msg2[] = "this is message 2";
  radio.write(&msg1, sizeof(msg1));
  Serial.println("sending message 1");
  delay(1000);
  radio.write(&msg2, sizeof(msg2));
  Serial.println("sending message 2");
  delay(1000);  
}
