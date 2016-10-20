const int blueLedPin = 13;
const int yellowButtonPin = 2;
const unsigned int forsinkelseStart = 10;
const unsigned int forsinkelseSlutt = 5000;
const unsigned int forsinkelsesOekning = 499;

unsigned long lastChange = 0;
unsigned long currentDelay = 10;
int blueLedValue = HIGH;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
}

void loop() {
  if (millis() - lastChange >= currentDelay) {
    lastChange = millis();
    blueLedValue = !blueLedValue;
    if (blueLedValue == LOW)
      currentDelay = currentDelay + forsinkelsesOekning;
    if (currentDelay >= forsinkelseSlutt)
      currentDelay = forsinkelseStart;
  }
  if (digitalRead(yellowButtonPin)) {
    currentDelay = 10;
  }
  digitalWrite(blueLedPin, blueLedValue);
}
