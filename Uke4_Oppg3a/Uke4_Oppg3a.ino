const unsigned int antallStjerner = 7;

void skrivStjerner(unsigned int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  skrivStjerner(antallStjerner);
  while (!Serial.available());
  Serial.read();
}

void skrivStjerner(unsigned int antall) {
  for (int i = 0; i < antall; ++i)
    Serial.print('*');
  Serial.println();
}

