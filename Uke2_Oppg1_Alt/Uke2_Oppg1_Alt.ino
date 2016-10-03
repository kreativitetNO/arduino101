const int blueLedPin = 13;
const int yellowButtonPin = 2;

void setup() {
  pinMode(blueLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
}

// Det er strengt talt ikke nødvendig å lagre det som leses
// siden det ikke brukes flere steder

void loop() {
  digitalWrite(blueLedPin, digitalRead(yellowButtonPin));
}
