const unsigned int innlesningsForsinkelse = 5;
const char letterToReplace = 'e';

void erstattE(String);

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
  erstattE(tekst);
}

void erstattE(String tekst) {
  tekst.replace("e", "i");
  Serial.println(tekst);
}
