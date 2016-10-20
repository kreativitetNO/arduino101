const int LED_PIN = 13;
const int INITIAL_DELAY = 10;
const int FINAL_DELAY = 5000;
const int DELAY_INCREASE = 499;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int i = INITIAL_DELAY; i <= FINAL_DELAY; i = i + DELAY_INCREASE) {
    digitalWrite(LED_PIN, HIGH);
    delay(i);
    digitalWrite(LED_PIN, LOW);
    delay(i);
  }
}
