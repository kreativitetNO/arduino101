const int YELLOW_BUTTON_PIN = 3;
const int GREEN_BUTTON_PIN = 4;
const int RED_BUTTON_PIN = 5;
const int LED_PIN = 10;
const int BLINK_DELAY = 250;

int buttonSum = 0;
int blueLedValue = 0;

void setup() {
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(RED_BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonSum = digitalRead(YELLOW_BUTTON_PIN)
    + digitalRead(GREEN_BUTTON_PIN)
    + digitalRead(RED_BUTTON_PIN);
  if (buttonSum == 1) {
    digitalWrite(LED_PIN, HIGH);
  }
  else if (buttonSum > 1) {
    digitalWrite(LED_PIN, HIGH);
    delay((4 - buttonSum) * BLINK_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay((4 - buttonSum) * BLINK_DELAY);
  }
  else
    digitalWrite(LED_PIN, LOW);
}
