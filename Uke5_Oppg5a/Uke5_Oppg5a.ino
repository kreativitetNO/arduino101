const unsigned int innlesningsForsinkelse = 10;

void setup() {
  Serial.begin(9600);
}

String lesTekst() {
  String resultat;
  while (Serial.available()) {
    resultat += (char)Serial.read();
    delay(innlesningsForsinkelse);
  }
  return resultat;
}

// :) (Dette er en kolon :)

String fjernParanteser(String tekst) {
  int dybde = 0;
  while (tekst.indexOf('(') > -1) {
    int startPos = 0;
    int sluttPos = 0;
    int i = 0;
    while (i < tekst.length() && sluttPos == 0) {
      if (tekst.charAt(i) == '(') {
        if (dybde == 0)
          startPos = i;
        dybde++;
      }
      if (tekst.charAt(i) == ')') {
        dybde--;
        if (dybde == 0)
          sluttPos = i;
      }
      ++i;
    }
    tekst.remove(startPos, sluttPos - startPos + 1);
  }
  return tekst;
}

String sistTekst;

void loop() {
  String tekst = lesTekst();
  if (tekst != sistTekst) {
    Serial.println(fjernParanteser(tekst));
  }
  sistTekst = tekst;
}
