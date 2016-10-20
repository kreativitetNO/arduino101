const int YELLOW_BUTTON_PIN = 2;
const int GREEN_BUTTON_PIN = 3;
const int BUZZER_PIN = 12;
const int SHORT_DELAY = 200;
const int LONG_DELAY = SHORT_DELAY * 2;

int greenButtonValue = LOW;
int yellowButtonValue = LOW;

void setup() {
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(GREEN_BUTTON_PIN)) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(LONG_DELAY);
    digitalWrite(BUZZER_PIN, LOW);
    while (digitalRead(GREEN_BUTTON_PIN));
  }
  else if (digitalRead(YELLOW_BUTTON_PIN)) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(SHORT_DELAY);
    digitalWrite(BUZZER_PIN, LOW);
    while (digitalRead(YELLOW_BUTTON_PIN));
  }
}
