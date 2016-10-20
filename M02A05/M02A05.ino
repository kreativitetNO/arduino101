const int POT_PIN = A0;
const int LED_PIN = 13;
const int MIDPOINT = 512;
const int MIN_BLINK_DELAY = 50;

int blinkDelay = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blinkDelay = abs(MIDPOINT - analogRead(POT_PIN)) + MIN_BLINK_DELAY;
  digitalWrite(LED_PIN, HIGH);
  delay(blinkDelay);
  digitalWrite(LED_PIN, LOW);
  delay(blinkDelay);
}
