const int blueLedPin = 13;
const int yellowButtonPin = 2;

int yellowButtonValue = LOW;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
}

void loop() {
  yellowButtonValue = digitalRead(yellowButtonPin);
  digitalWrite(blueLedPin, yellowButtonValue);
}
