const int ledPin = 4;
const int greenButtonPin = 3;

volatile int del = 1000;
unsigned int debounce = 10;
long lastPressed = 0;

void greenButtonPressed();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(greenButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(greenButtonPin), greenButtonPressed, FALLING);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(del);
  digitalWrite(ledPin, LOW);
  delay(del);
}

void greenButtonPressed() {
  if (millis() - lastPressed > 10) {
    del -= 50;
    if (del < 0)
      del = 0;
    lastPressed = millis();
  }
}
