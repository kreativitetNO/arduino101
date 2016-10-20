const int INPUT_DELAY = 5;

void findE(String);

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
  findE(text);
}

void findE(String text) {
  int index = text.indexOf('e');
  if (index < 0) {
    Serial.println("There is no 'e'");    
  }
  else {
    Serial.print("The first 'e' is at index ");
    Serial.println(index + 1);
  }
}
