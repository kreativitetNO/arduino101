const unsigned int innlesningsForsinkelse = 5;

void shout(String);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available());
  String tekst;
  while (Serial.available()) {
      tekst += char(Serial.read());
      delay(innlesningsForsinkelse);
  }
  shout(tekst);
}

void shout(String tekst) {
  tekst.toUpperCase();
  Serial.println(tekst);
}
