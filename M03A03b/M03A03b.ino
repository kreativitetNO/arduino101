const int LED_PIN = 13;
const int INITIAL_DELAY = 10;
const int FINAL_DELAY = 5000;
const int DELAY_INCREASE = 499;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int i = INITIAL_DELAY;
  while (i <= FINAL_DELAY) {
    digitalWrite(LED_PIN, HIGH);
    delay(i);
    digitalWrite(LED_PIN, LOW);
    delay(i);
    i += DELAY_INCREASE;
  }
}
