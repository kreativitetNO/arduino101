const int yellowButtonPin = 2;
const int greenButtonPin = 3;
const int buzzerPin = 12;
const int shortDelay = 200;
const int longDelay = shortDelay * 2;

int greenButtonValue = LOW;
int yellowButtonValue = LOW;

void setup() {
  pinMode(yellowButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(greenButtonPin)) {
    digitalWrite(buzzerPin, HIGH);
    delay(longDelay);
    digitalWrite(buzzerPin, LOW);
    while (digitalRead(greenButtonPin));
  }
  else if (digitalRead(yellowButtonPin)) {
    digitalWrite(buzzerPin, HIGH);
    delay(shortDelay);
    digitalWrite(buzzerPin, LOW);
    while (digitalRead(yellowButtonPin));
  }
}
