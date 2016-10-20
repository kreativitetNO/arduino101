const int LED_PIN = 13;
const int BUZZER_PIN = 12;
const int BLINK_CODE = 1;
const int BUZZ_CODE = 2;

int actionCode;
int value;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    actionCode = Serial.parseInt();
    value = Serial.parseInt();
  }
  if (actionCode == BLINK_CODE) {
    digitalWrite(LED_PIN, HIGH);
    delay(value);
    digitalWrite(LED_PIN, LOW);
    delay(value);
  }
  else if (actionCode == BUZZ_CODE) {
    analogWrite(BUZZER_PIN, value);
  }
  else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}
