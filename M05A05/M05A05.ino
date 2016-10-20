const int INPUT_DELAY = 10;

String getText();
void removeParentheses(String);

void setup() {
  Serial.begin(9600);
}

void loop() {
  String text = getText();
  removeParentheses(text);
}

String getText() {
  String result;
  while (!Serial.available());
  while (Serial.available()) {
    result += (char)Serial.read();
    delay(INPUT_DELAY);
  }
  return result;
}

void removeParentheses(String text) {
  int depth = 0;
  while (text.indexOf('(') > -1) {
    int startPos = 0;
    int endPos = 0;
    int i = 0;
    while (i < text.length() && endPos == 0) {
      if (text.charAt(i) == '(') {
        if (depth == 0)
          startPos = i;
        depth++;
      }
      if (text.charAt(i) == ')') {
        depth--;
        if (depth == 0)
          endPos = i;
      }
      ++i;
    }
    text.remove(startPos, endPos - startPos + 1);
  }
  Serial.println(text);
}

