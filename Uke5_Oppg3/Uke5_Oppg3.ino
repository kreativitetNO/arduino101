const unsigned int innlesningsForsinkelse = 5;

void finnE(String);

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
  finnE(tekst);
}

void finnE(String tekst) {
  int plass = tekst.indexOf('e');
  if (plass < 0) {
    Serial.println("Det fins ingen e");    
  }
  else {
    Serial.print("Den foerste e er paa plass ");
    Serial.println(plass + 1); // smaksak om du legger til 1 eller ikke - hvorfor?
  }
}
