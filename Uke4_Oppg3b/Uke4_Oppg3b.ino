const unsigned int LINE_COUNT = 5;

void writeStars(int);
void writeManyStars(int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  writeManyStars(LINE_COUNT);
  while (!Serial.available());
  Serial.read();
}

void writeStars(int count) {
  for (int i = 0; i < count; ++i)
    Serial.print('*');
  Serial.println();
}

void writeManyStars(int count) {
  for (int i = 0; i < count; ++i)
    writeStars(i+1);
}

