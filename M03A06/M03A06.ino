const int LED_PIN = 13;
const int BUZZER_PIN = 12;
const int YELLOW_BUTTON_PIN = 2;
const int GREEN_BUTTON_PIN = 3;
const int SIGNAL_TIME = 500;
const int INPUT_DELAY = 20;

long yellowPressed = 0;
long greenPressed = 0;
int buttonsPressed = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(YELLOW_BUTTON_PIN, INPUT);
  pinMode(GREEN_BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(YELLOW_BUTTON_PIN)) {
    delay(INPUT_DELAY);
    while (digitalRead(YELLOW_BUTTON_PIN));
    yellowPressed = millis();
    buttonsPressed++;
  }
  if (digitalRead(GREEN_BUTTON_PIN)) {
    delay(INPUT_DELAY);
    while (digitalRead(GREEN_BUTTON_PIN));
    greenPressed = millis();
    buttonsPressed++;
  }
  if (buttonsPressed == 2) {
    if (yellowPressed == 0 || greenPressed == 0
        || (greenPressed < yellowPressed)) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(SIGNAL_TIME);
      digitalWrite(BUZZER_PIN, LOW);
    }
    else {
      digitalWrite(LED_PIN, HIGH);
      delay(SIGNAL_TIME);
      digitalWrite(LED_PIN, LOW);
    }
    yellowPressed = greenPressed = buttonsPressed = 0;
  }
}
