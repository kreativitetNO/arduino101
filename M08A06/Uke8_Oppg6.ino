#include <IRremote.h>

const unsigned int irrecvPin = 11;
const unsigned int rgbLedRedPin = 10;
const unsigned int rgbLedGreenPin = 9;
const unsigned int rgbLedBluePin = 8;

struct RGB {
  unsigned int r;
  unsigned int g;
  unsigned int b;
};

void setRGBLed(const RGB& rgb);
void processIRCode_bad(RGB& rgb, const unsigned long& code);
void processIRCode_good(RGB& rgb, const unsigned long& code);

RGB rgb;
IRrecv irrecv(irrecvPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  //  processIRCode_bad(rgb, results.value);
  processIRCode_good(rgb, results.value);
  setRGBLed(rgb);
}

void setRGBLed(const RGB& rgb) {
  analogWrite(rgbLedRedPin, rgb.r);
  analogWrite(rgbLedGreenPin, rgb.g);
  analogWrite(rgbLedBluePin, rgb.b);
}

void processIRCode_bad(RGB& rgb, const unsigned long& code) {
  if (code == 0xFF30CF) {
    rgb.g = 255;
  }
  else if (code == 0xFF18E7) {
    rgb.r = 255;
  }
  else if (code == 0xFF7A85) {
    rgb.b = 255;
  }
  else if (code == 0xFF10EF) {
    rgb.g = 0;
  }
  else if (code == 0xFF38C7) {
    rgb.r = 0;
  }
  else if (code == 0xFF5AA5) {
    rgb.b = 0;
  }
}

void processIRCode_good(RGB& rgb, const unsigned long& code) {
  switch (code) {
    case 0xFF30CF: rgb.g = 255; break;
    case 0xFF18E7: rgb.r = 255; break;
    case 0xFF7A85: rgb.b = 255; break;
    case 0xFF10EF: rgb.g = 0; break;
    case 0xFF38C7: rgb.r = 0; break;
    case 0xFF5AA5: rgb.b = 0; break;
  }
}

