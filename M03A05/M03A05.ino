const int LED_PIN = 13;
const int MAX_REPS  = 10;
const int BLINK_DELAY = 500;

int ledValue = LOW;
int currentRepetitions = 0;
unsigned long lastChange = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (currentRepetitions < MAX_REPS) {
    if (millis() - lastChange >= BLINK_DELAY) {
      lastChange = millis();
      currentRepetitions++;
      ledValue = !ledValue;
      digitalWrite(LED_PIN, ledValue);
    }
  }
}
