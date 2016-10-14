const int potPin = A0;
const unsigned int antallMaalinger = 50;
const unsigned int maaleIntervall = 250;

unsigned int maaleVerdier[antallMaalinger];

void skrivSum();
void skrivSnitt();
void skrivMinMaks();
void skrivMedian();

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    maaleVerdier[i] = analogRead(potPin);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(maaleVerdier[i]);
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
    sum += maaleVerdier[i];
  }
  Serial.print("Summen av maalingene er: ");
  Serial.println(sum);
}

void skrivSnitt() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    sum += maaleVerdier[i];
  }
  Serial.print("Snittet av maalingene er: ");
  Serial.println(1.0*sum/antallMaalinger);
}

void skrivMinMaks() {
  unsigned int minVerdi = 1023;
  unsigned int maksVerdi = 0;
  for (unsigned int i = 0; i < antallMaalinger; ++i) {
    minVerdi = min(maaleVerdier[i], minVerdi);
    maksVerdi = max(maaleVerdier[i], maksVerdi);
  }
  Serial.print("Min og maks er: ");
  Serial.print(minVerdi);
  Serial.print(" og ");
  Serial.println(maksVerdi);
}

void skrivMedian() {
  // Insertion sort - se Wikipedia
  for (unsigned int i = 1; i < antallMaalinger; ++i) {
    unsigned int j = i;
    while (maaleVerdier[j] < maaleVerdier[j-1] && j > 0) {
      unsigned int temp = maaleVerdier[j];
      maaleVerdier[j] = maaleVerdier[j-1];
      maaleVerdier[j-1] = temp;
      j--;
    }
  }
  // Sortering ferdig
  
  Serial.print("Median er: ");
  if (antallMaalinger % 2 == 0) { // partall
    Serial.println((maaleVerdier[antallMaalinger/2]+maaleVerdier[antallMaalinger/2-1])/2.0);
  }
  else {
    Serial.println(maaleVerdier[antallMaalinger/2]);
  }
}

