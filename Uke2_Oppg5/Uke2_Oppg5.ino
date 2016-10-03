const int potPin = A0;
const int blueLedPin = 13;
const unsigned int midtPunkt = 512;

void setup() {
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  int del = abs(midtPunkt - analogRead(potPin));
  digitalWrite(blueLedPin, HIGH);
  delay(del);
  digitalWrite(blueLedPin, LOW);
  delay(del);
}
