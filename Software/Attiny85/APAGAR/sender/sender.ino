#define CE_PIN 3
#define CSN_PIN 4 //Since we are using 3 pin configuration we will use same pin for both CE and CSN
// CE_PIN 3 and CSN_PIN 4
#include "RF24.h"

RF24 radio(CE_PIN, CSN_PIN);

uint64_t address = 0xE14BC8F482LL; //byte address[11] = "SimpleNode";
unsigned long payload = 0;

void setup() {
  radio.begin(); // Start up the radio
  radio.setAutoAck(1); // Ensure autoACK is enabled
  radio.setRetries(15,15); // Max delay between retries & number of retries
  radio.openWritingPipe(address); // Write to device address 'SimpleNode'
}

void loop(void){
  payload++;
  radio.write( &payload, sizeof(unsigned long) ); //Send data to 'Receiver' ever second
  delay(1000);
}
