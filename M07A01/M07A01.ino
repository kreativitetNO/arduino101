int abs1(int tall);
void abs2(int& tall);
void abs3(int* tall);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int tall1 = -2;
  int tall2 = -7;
  int tall3 = -4;
  tall1 = abs1(tall1);
  abs2(tall2);
  abs3(&tall3);
  Serial.print(tall1);
  Serial.print(tall2);
  Serial.println(tall3);
}

int abs1(int tall) {
  if (tall < 0) {
    return -1 * tall;  
  }
  return tall;
}

void abs2(int& tall) {
  if (tall < 0) {
    tall = -1 * tall;
  }
}

void abs3(int* tall) {
  if (*tall < 0) {
    *tall = -1 * *tall;
  }
}

