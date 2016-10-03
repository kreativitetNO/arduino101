const int blueLedPin = 13;
const int maxRepetitions  = 10; // Tenk litt på hvorfor...

int blueLedValue = LOW;
int currentRepetitions = 0;
long lastChange = 0;
long blinkDelay = 500;

void setup() {
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  if (currentRepetitions < maxRepetitions) {
    if (millis() - lastChange >= blinkDelay) {
      lastChange = millis();
      currentRepetitions++;
      blueLedValue = !blueLedValue;
      digitalWrite(blueLedPin, blueLedValue);
    }
  }
}
