const int ledPin = 4;
const int greenButtonPin = 3;

volatile int ledValue = HIGH;
volatile long lastPressed = 0;

void buttonPressed();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(greenButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(greenButtonPin), buttonPressed, CHANGE);
}

void loop() {
  digitalWrite(ledPin, ledValue);
}

void buttonPressed() {
  if (millis() - lastPressed > 20) {
    ledValue = !ledValue;
    lastPressed = millis();
  }
}

