const int LED_PIN = 13;
const int BUTTON_PIN = 2;
const int BLINK_DELAY = 5000;

int ledValue = LOW;
long lastUpdate = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (millis() - lastUpdate >= BLINK_DELAY) {
    ledValue = !ledValue;
    lastUpdate = millis();
  }
  digitalWrite(LED_PIN, ledValue || digitalRead(BUTTON_PIN));
}
