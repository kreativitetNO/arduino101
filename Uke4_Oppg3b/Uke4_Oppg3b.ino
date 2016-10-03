const unsigned int antallLinjer = 5;

void skrivStjerner(unsigned int);
void skrivMangeStjerner(unsigned int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  skrivMangeStjerner(antallLinjer);
  while (!Serial.available());
  Serial.read();
}

void skrivStjerner(unsigned int antall) {
  for (int i = 0; i < antall; ++i)
    Serial.print('*');
  Serial.println();
}

void skrivMangeStjerner(unsigned int antall) {
  for (int i = 0; i < antall; ++i)
    skrivStjerner(i+1);
}

