const int INPUT_DELAY = 5;

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
  Serial.print(text);
  Serial.print(" has length ");
  Serial.println(text.length());
}
