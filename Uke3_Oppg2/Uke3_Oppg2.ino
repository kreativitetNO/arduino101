const int blueLedPin = 13;
const int yellowButtonPin = 2;
const unsigned int blinkForsinkelse = 5000;

int blueLedValue = LOW;
long lastUpdate = 0;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
}

void loop() {
  if (millis() - lastUpdate >= blinkForsinkelse) {
    lastUpdate = millis();
    blueLedValue = !blueLedValue;
  }
  digitalWrite(blueLedPin, blueLedValue || digitalRead(yellowButtonPin));
}
