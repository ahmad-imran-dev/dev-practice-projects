#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
  if(results.value != 0xFFFFFFFF)
   {
    Serial.println(results.value, DEC);
   }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}






//
