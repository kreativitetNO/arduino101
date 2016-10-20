const unsigned int STAR_COUNT = 7;

void writeStars(int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  writeStars(STAR_COUNT);
  while (!Serial.available());
  Serial.read();
}

void writeStars(int count) {
  for (int i = 0; i < count; ++i)
    Serial.print('*');
  Serial.println();
}

