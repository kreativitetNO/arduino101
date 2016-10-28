const int primtall[] =
  { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
    37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
    79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163,
    167, 173, 179, 181 };
const int maksAntallFaktorer = 20;

void initialiser(int*, int);
int hentTall();
void faktoriser(int, int*, int);
void skrivUt(int, int*, int);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  int faktorer[maksAntallFaktorer];
  initialiser(faktorer, maksAntallFaktorer);
  int tall = hentTall();
  faktoriser(tall, faktorer, maksAntallFaktorer);
  skrivUt(tall, faktorer, maksAntallFaktorer);
}

void initialiser(int* arr, int len) {
  for (unsigned int i = 0; i < len; ++i) {
    arr[i] = 0;
  }
}

int hentTall() {
  while (!Serial.available());
  return Serial.parseInt();
}

void faktoriser(int tall, int* arr, int len) {
  int i = 0;
  int j = 0;
  while (i < len - 1 && tall != 1) {
    if (tall % primtall[j] == 0) {
      tall = tall / primtall[j];
      arr[i] = primtall[j];
      i++;
    }
    else {
      j++;
    }
  }
  if (tall != 1) {
    arr[len - 1] = tall;
  }
}

void skrivUt(int tall, int* arr, int len) {
  Serial.print(tall);
  Serial.print("=");
  for (unsigned int i = 0; i < len; ++i) {
    if (arr[i] != 0)
      Serial.print(arr[i]);
    if (i < len - 1 && arr[i + 1] != 0)
      Serial.print("x");
  }
  Serial.println();
}

