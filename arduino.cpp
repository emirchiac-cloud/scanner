void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Send data directly over USB
  Serial.println("HelloFromArduino"); 
  delay(5000); // Send every 5 seconds
}