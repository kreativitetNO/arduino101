const int POT_PIN = A7;
const int LED_PIN = 6;
const int BUZZER_PIN = 5;
const int LED_UPPER_THRESHOLD = 300;
const int BUZZER_LOWER_THRESHOLD = 1000;

int potValue = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  potValue = analogRead(POT_PIN);
  digitalWrite(LED_PIN, potValue < LED_UPPER_THRESHOLD);
  digitalWrite(BUZZER_PIN, potValue > BUZZER_LOWER_THRESHOLD);
}
