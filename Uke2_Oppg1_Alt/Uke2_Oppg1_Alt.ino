const int LED_PIN = 10;
const int BUTTON_PIN = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  digitalWrite(LED_PIN, digitalRead(BUTTON_PIN));
}
