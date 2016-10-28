const int joyXPin = A0;
const int joyYPin = A1;
const int joyButtonPin = 7;

struct JoystickData {
  int x;
  int y;
  bool buttonPressed;
};

JoystickData joy;

void readJoyValues(JoystickData& joy);
void writeJoyValues(JoystickData& joy);
void writeLeftPadded(int val);

void setup() {
  Serial.begin(9600);
  pinMode(joyButtonPin, INPUT);
}

void loop() {
  readJoystickValues(joy);
  writeJoystickValues(joy);
}

void readJoystickValues(JoystickData& joy) {
  joy.x = analogRead(joyXPin);
  joy.y = analogRead(joyYPin);
  // Hvis du har en annen joystick enn meg (som ikke har egne
  // +5v og GND på både knappen, X og Y-aksene) så kan det
  // hende at du må koble den til en analog inngang siden
  // det virker som den ikke sender nok volt til å bli oppfattet
  // som høy. Merk at knappen returner 0 når den er trykket.
  joy.buttonPressed = digitalRead(joyButtonPin) == 0;
}

void writeLeftPadded(int val) {
  if (val < 10) {
    Serial.print(' ');
  }
  if (val < 100) {
    Serial.print(' ');
  }
  if (val < 1000) {
    Serial.print(' ');
  }
  Serial.print(val);
}

void writeJoystickValues(JoystickData& joy) {
  Serial.print("x: ");
  writeLeftPadded(joy.x);
  Serial.print(" y: ");
  writeLeftPadded(joy.y);
  Serial.print(" button: ");
  if (joy.buttonPressed) {
    Serial.println("yes");
  }
  else {
    Serial.println("no");
  }
}
