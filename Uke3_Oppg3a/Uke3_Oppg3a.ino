const int blueLedPin = 13;
const unsigned int forsinkelseStart = 10;
const unsigned int forsinkelseSlutt = 5000;
const unsigned int forsinkelsesOekning = 499;

void setup() {
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  for (int i = forsinkelseStart; i <= forsinkelseSlutt; i = i + forsinkelsesOekning) {
    digitalWrite(blueLedPin, HIGH);
    delay(i);
    digitalWrite(blueLedPin, LOW);
    delay(i);
  }
}
