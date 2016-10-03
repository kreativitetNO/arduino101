unsigned long fakultet(int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int input = Serial.parseInt();
    Serial.print("Fakultet av ");
    Serial.print(input);
    Serial.print(" er: ");
    Serial.println(fakultet(input));
  }
}

unsigned long fakultet(int tall) {
  if (tall < 2)
    return 1;
  if (tall > 13) {
    Serial.println("Kan ikke regne ut fakultet av tall over 13");
    return -1;
  }
  long svar = 1;
  for (int i = 2; i <= tall; ++i)
    svar *= i;
  return svar; 
}

