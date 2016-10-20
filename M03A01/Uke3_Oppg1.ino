const int blueLedPin = 13;
const int yellowButtonPin = 2;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
}

void loop() {
  if (digitalRead(yellowButtonPin)) {
    digitalWrite(blueLedPin, HIGH);
    while (digitalRead(yellowButtonPin));
    digitalWrite(blueLedPin, LOW);
  }
  digitalWrite(blueLedPin, HIGH);
  delay(5000);
  digitalWrite(blueLedPin, LOW);
  delay(5000);
}
