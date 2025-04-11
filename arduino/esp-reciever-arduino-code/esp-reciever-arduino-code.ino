void setup() {
  Serial.begin(9600);
}

void loop() {
  // Check for incoming serial commands
  if (Serial.available() > 0) {
    int command = Serial.read();
    
    // Process the received command
    switch (command) {
      case 0:
        Serial.println(command);
        break;
      case 1:
        Serial.println(command);
        break;
      case 2:
        Serial.println(command);
        break;
      case 3:
        Serial.println(command);
        break;
      case 4:
        Serial.println(command);
        break;
      case 5:
        Serial.println(command);
        break;
      case 6:
        Serial.println(command);
        break;
      case 7:
        Serial.println(command);
        break;
      case 8:
        Serial.println(command);
        break;
      case 9:
        Serial.println(command);
        break;
      case 10:
        Serial.println(command);
        break;
      case 11:
        Serial.println(command);
        break;
      case 12:
        Serial.println(command);
        break;
    }
  }
}
