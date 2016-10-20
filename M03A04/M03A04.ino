const int LED_PIN = 13;
const int BUTTON_PIN = 2;
const int INITIAL_DELAY = 10;
const int FINAL_DELAY = 5000;
const int DELAY_INCREASE = 499;

unsigned long lastChange = 0;
unsigned long currentDelay = 10;
int ledValue = HIGH;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (millis() - lastChange >= currentDelay) {
    lastChange = millis();
    ledValue = ledValue;
    if (blueLedValue == LOW)
      currentDelay = currentDelay + DELAY_INCREASE;
    if (currentDelay >= FINAL_DELAY)
      currentDelay = INITIAL_DELAY;
  }
  if (digitalRead(BUTTON_PIN)) {
    currentDelay = 10;
  }
  digitalWrite(LED_PIN, blueLedValue);
}
