const int YELLOW_BUTTON_PIN = 4;
const int GREEN_BUTTON_PIN = 5;
const int LED_PIN = 10;
const int BLINK_DELAY = 250;

int buttonSum = 0;
int ledValue = 0;

void setup() {
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonSum = digitalRead(YELLOW_BUTTON_PIN)
    + digitalRead(GREEN_BUTTON_PIN);
  if (buttonSum == 1) {
    digitalWrite(LED_PIN, HIGH);
  }
  else if (buttonSum == 2) {
    digitalWrite(LED_PIN, HIGH);
    delay(BLINK_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(BLINK_DELAY);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
}
