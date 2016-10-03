const unsigned int innlesningsForsinkelse = 5;

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
  Serial.print(tekst);
  Serial.print(" har lengde ");
  Serial.println(tekst.length());
}
