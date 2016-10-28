const int ledPin = 4;
const int greenButtonPin = 2;
const int yellowButtonPin = 3;

volatile int del = 1000;
unsigned int debounce = 10;
long lastGreenPressed = 0;
long lastYellowPressed = 0;

void greenButtonPressed();
void yellowButtonPressed();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(yellowButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(greenButtonPin), greenButtonPressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(yellowButtonPin), yellowButtonPressed, FALLING);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(del);
  digitalWrite(ledPin, LOW);
  delay(del);
}

void greenButtonPressed() {
  if (millis() - lastGreenPressed > debounce) {
    del -= 50;
    if (del < 0)
      del = 0;
      lastGreenPressed = millis();
  }
}

void yellowButtonPressed() {
  if (millis() - lastYellowPressed > debounce) {
    del += 50;
    if (del > 1000)
      del = 1000;
      lastYellowPressed = millis();
  }
}
