const int LED_PIN = 13;

int blueLedValue = HIGH;
int blinkDelay = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    blinkDelay = Serial.parseInt();
  }
  digitalWrite(LED_PIN, blueLedValue);
  delay(blinkDelay);
  blueLedValue = !blueLedValue;
  Serial.println(blinkDelay);  
}
