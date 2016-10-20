const int INPUT_DELAY = 5;
const char LETTER_TO_REPLACE = 'e';
const char LETTER_TO_INSERT = 'i';

void replaceE(String);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (!Serial.available());
  String text;
  while (Serial.available()) {
      text += char(Serial.read());
      delay(INPUT_DELAY);
  }
  replaceE(text);
}

void replaceE(String text) {
  text.replace(LETTER_TO_REPLACE, LETTER_TO_INSERT);
  Serial.println(text);
}
