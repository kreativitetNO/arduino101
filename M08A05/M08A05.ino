const int joyXPin = A0;
const int joyYPin = A1;
const int joyButtonPin = 7;
const int rgbLedRedPin = 10;
const int rgbLedGreenPin = 9;
const int rgbLedBluePin = 8;

struct JoystickData {
  int x;
  int y;
  // Joysticken står ikke nødvendigvis helt i midten når du
  // slipper den. Derfor leser jeg av joystick-verdien i setup
  // for å få korrekt midtstilling.
  int centerX;
  int centerY;
  // Mange joystick "svever" mellom 2-3 forskjellige verdier
  // selv om de står stille. Derfor definerer jeg en dødsone
  int deadzoneX;
  int deadzoneY;
  bool buttonPressed;
};

struct RGB {
  int r;
  int g;
  int b;
};

JoystickData joy;
RGB rgb;

void readJoyValues(JoystickData& joy);
void setRGBLed(const RGB& rgb);
unsigned int convertInOut(int val, int deadzone, int center);

void setup() {
  Serial.begin(9600);
  pinMode(joyButtonPin, INPUT);
  pinMode(rgbLedRedPin, OUTPUT);
  pinMode(rgbLedGreenPin, OUTPUT);
  pinMode(rgbLedBluePin, OUTPUT);
  joy.centerX = analogRead(joyXPin);
  joy.centerY = analogRead(joyYPin);
}

void loop() {
  readJoystickValues(joy);
  if (joy.buttonPressed) {
    rgb.r = 0;
    rgb.g = 255;
    rgb.b = 0;
  }
  else {
    rgb.r = convertInOut(joy.x, joy.deadzoneX, joy.centerX);
    rgb.g = 0;
    rgb.b = convertInOut(joy.y, joy.deadzoneY, joy.centerY);
  }
  setRGBLed(rgb);
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

void setRGBLed(const RGB& rgb) {
  analogWrite(rgbLedRedPin, rgb.r);
  analogWrite(rgbLedGreenPin, rgb.g);
  analogWrite(rgbLedBluePin, rgb.b);
}

int convertInOut(int val, int deadzone, int center) {
  if (val < center + deadzone / 2 && val > center - deadzone / 2)
    return center / 4;
  return val / 4;
}

