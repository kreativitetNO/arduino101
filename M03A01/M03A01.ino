const int LED_PIN = 13;
const int BUTTON_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN)) {
    digitalWrite(LED_PIN, HIGH);
    while (digitalRead(BUTTON_PIN));
    digitalWrite(LED_PIN, LOW);
  }
  digitalWrite(LED_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_PIN, LOW);
  delay(5000);
}
