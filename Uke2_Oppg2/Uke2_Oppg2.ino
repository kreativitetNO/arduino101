const int yellowButtonPin = 2;
const int greenButtonPin = 3;
const int blueLedPin = 13;
const unsigned int forsinkelsesFaktor = 250;

int buttonSum = 0;
int blueLedValue = 0;

void setup() {
  pinMode(yellowButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  buttonSum = digitalRead(yellowButtonPin)
    + digitalRead(greenButtonPin);
  if (buttonSum == 1) {
    digitalWrite(blueLedPin, HIGH);
  }
  else if (buttonSum == 2) {
    digitalWrite(blueLedPin, HIGH);
    delay(forsinkelsesFaktor);
    digitalWrite(blueLedPin, LOW);
    delay(forsinkelsesFaktor);
  }
  else {
    digitalWrite(blueLedPin, LOW);
  }
}
