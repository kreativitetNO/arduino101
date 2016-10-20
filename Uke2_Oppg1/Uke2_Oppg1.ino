const int LED_PIN = 10;
const int BUTTON_PIN = 5;

int buttonValue = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonValue = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, buttonValue);
}
