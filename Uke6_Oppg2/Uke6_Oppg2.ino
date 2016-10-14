const int potPin = A0;
const unsigned int antallMaalinger = 50;
const unsigned int maaleIntervall = 250;

struct MaaleVerdi {
  unsigned int data;
  unsigned long tidspunkt;
};

MaaleVerdi maaleVerdier[antallMaalinger];

void skrivSum();
void skrivSnitt();
void skrivMinMaks();
void skrivMedian();

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    maaleVerdier[i].tidspunkt = millis();
    maaleVerdier[i].data = analogRead(potPin);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(maaleVerdier[i].data);
    delay(maaleIntervall);
  }
  skrivSum();
  skrivSnitt();
  skrivMinMaks();
  skrivMedian();
  while (!Serial.available());
  Serial.read();
}

void skrivSum() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    sum += maaleVerdier[i].data;
  }
  Serial.print("Summen av maalingene er: ");
  Serial.println(sum);
}

void skrivSnitt() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    sum += maaleVerdier[i].data;
  }
  Serial.print("Snittet av maalingene er: ");
  Serial.println(1.0*sum/antallMaalinger);
}

void skrivMinMaks() {
  unsigned int minVerdi = 1023;
  unsigned int maksVerdi = 0;
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    minVerdi = min(maaleVerdier[i].data, minVerdi);
    maksVerdi = max(maaleVerdier[i].data, maksVerdi);
  }
  Serial.print("Min verdien er: ");
  Serial.println(minVerdi);
  Serial.print("Dette skjedde ved: ");
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    if (maaleVerdier[i].data == minVerdi) {
      Serial.print(maaleVerdier[i].tidspunkt);
      Serial.print(" ");
    }
  }
  Serial.println();
  Serial.print("Maks verdien er: ");
  Serial.println(maksVerdi);
  Serial.print("Dette skjedde ved: ");
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    if (maaleVerdier[i].data == maksVerdi) {
      Serial.print(maaleVerdier[i].tidspunkt);
      Serial.print(" ");
    }
  }
  Serial.println();
}

void skrivMedian() {
  // Insertion sort - se Wikipedia
  for (unsigned int i = 1; i < antallMaalinger; ++i) {
    unsigned int j = i;
    while (maaleVerdier[j].data < maaleVerdier[j-1].data && j > 0) {
      MaaleVerdi temp = maaleVerdier[j];
      maaleVerdier[j] = maaleVerdier[j-1];
      maaleVerdier[j-1] = temp;
      j--;
    }
  }
  // Sortering ferdig
  
  Serial.print("Median er: ");
  if (antallMaalinger % 2 == 0) { // partall
    Serial.println((maaleVerdier[antallMaalinger/2].data+maaleVerdier[antallMaalinger/2-1].data)/2.0);
  }
  else {
    Serial.println(maaleVerdier[antallMaalinger/2].data);
  }
}

