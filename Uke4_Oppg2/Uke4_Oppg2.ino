const int blueLedPin = 13;
const int buzzerPin = 12;
const int blinkCode = 1;
const int buzzCode = 2;

int actionCode;
int value;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    actionCode = Serial.parseInt();
    value = Serial.parseInt();
  }
  if (actionCode == blinkCode) {
    digitalWrite(blueLedPin, HIGH);
    delay(value);
    digitalWrite(blueLedPin, LOW);
    delay(value);
  }
  else if (actionCode == buzzCode) {
    analogWrite(buzzerPin, value);
  }
  else {
    digitalWrite(blueLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
