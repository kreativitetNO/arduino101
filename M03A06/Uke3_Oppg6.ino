const int blueLedPin = 13;
const int buzzerPin = 12;
const int yellowButtonPin = 2;
const int greenButtonPin = 3;
const int signalTime = 500;

long yellowPressed = 0;
long greenPressed = 0;
int buttonsPressed = 0;


void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
}

void loop() {
  if (digitalRead(yellowButtonPin)) {
    delay(20);
    while (digitalRead(yellowButtonPin));
    yellowPressed = millis();
    buttonsPressed++;
  }
  if (digitalRead(greenButtonPin)) {
    delay(20);
    while (digitalRead(greenButtonPin));
    greenPressed = millis();
    buttonsPressed++;
  }
  if (buttonsPressed == 2) {
    if (yellowPressed == 0 || greenPressed == 0
        || (greenPressed < yellowPressed)) {
      digitalWrite(buzzerPin, HIGH);
      delay(signalTime);
      digitalWrite(buzzerPin, LOW);
    }
    else {
      digitalWrite(blueLedPin, HIGH);
      delay(signalTime);
      digitalWrite(blueLedPin, LOW);
    }
    yellowPressed = greenPressed = buttonsPressed = 0;
  }
}
