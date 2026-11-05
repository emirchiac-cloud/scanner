const int greenPin = 3; 
const int redPin = 6;   

unsigned long previousMillis = 0;
const long interval = 5000; // 5 seconds
bool ledsActive = false;

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // Check for incoming serial commands from the Python/PHP program
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "true") {
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      previousMillis = millis(); // Reset the 5-second timer
      ledsActive = true;
    } else if (command == "false") {
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, HIGH);
      previousMillis = millis(); // Reset the 5-second timer
      ledsActive = true;
    }
  }

  // Automatically turn off LEDs after 5 seconds without blocking the program
  if (ledsActive && (millis() - previousMillis >= interval)) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    ledsActive = false;
  }
}