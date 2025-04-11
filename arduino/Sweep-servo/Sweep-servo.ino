
#include <Servo.h>

Servo myservo1;  // create Servo object to control a servo
Servo myservo2;
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(2);  // attaches the servo on pin 9 to the Servo object
  myservo2.attach(3);
}

void loop() {
  for (pos = 0; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 150; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  delay(500);
  for (pos = 0; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 150; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
}
