const int INPUT_DELAY = 5;

void shout(String);

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
  shout(text);
}

void shout(String text) {
  text.toUpperCase();
  Serial.println(text);
}
