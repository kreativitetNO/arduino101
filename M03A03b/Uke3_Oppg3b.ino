const int blueLedPin = 13;
const unsigned int forsinkelseStart = 10;
const unsigned int forsinkelseSlutt = 5000;
const unsigned int forsinkelsesOekning = 499;

void setup() {
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  int i = forsinkelseStart;
  while (i <= forsinkelseSlutt) {
    digitalWrite(blueLedPin, HIGH);
    delay(i);
    digitalWrite(blueLedPin, LOW);
    delay(i);
    i = i + forsinkelsesOekning;
  }
}
