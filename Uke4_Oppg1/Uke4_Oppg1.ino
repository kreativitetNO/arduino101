const int blueLedPin = 13;

int blueLedValue = HIGH;
int blinkDelay = 0;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    blinkDelay = Serial.parseInt();
  }
  digitalWrite(blueLedPin, blueLedValue);
  delay(blinkDelay);
  blueLedValue = !blueLedValue;
  Serial.println(blinkDelay);  
}
