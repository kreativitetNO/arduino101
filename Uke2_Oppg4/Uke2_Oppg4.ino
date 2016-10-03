const int potPin = A0;
const int blueLedPin = 13;
const int buzzerPin = 12;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  digitalWrite(blueLedPin, potValue < 300);
  digitalWrite(buzzerPin, potValue > 1000);
}
