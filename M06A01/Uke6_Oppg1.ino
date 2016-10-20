const int POT_PIN = A0;
const unsigned int MEASUREMENT_COUNT = 50;
const unsigned int MEASUREMENT_INTERVAL = 250;

unsigned int measurements[MEASUREMENT_COUNT];

void skrivSum();
void skrivSnitt();
void skrivMinMaks();
void skrivMedian();

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    measurements[i] = analogRead(POT_PIN);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(measurements[i]);
    delay(MEASUREMENT_INTERVAL);
  }
  outputSum();
  outputAverage();
  outputMinMax();
  outputMedian();
  while (!Serial.available());
  Serial.read();
}

void outputSum() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    sum += measurements[i];
  }
  Serial.print("The sum of the measurements is: ");
  Serial.println(sum);
}

void outputAverage() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    sum += measurements[i];
  }
  Serial.print("The average measurement is: ");
  Serial.println(1.0*sum/MEASUREMENT_COUNT);
}

void outputMinMax() {
  unsigned int minValue = 1023;
  unsigned int maxValue = 0;
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    minValue = min(measurements[i], minValue);
    maxValue = max(measurements[i], maxValue);
  }
  Serial.print("Min and max: ");
  Serial.print(minValue);
  Serial.print(" ");
  Serial.println(maxValue);
}

void outputMedian() {
  // Insertion sort - see Wikipedia
  for (unsigned int i = 1; i < MEASUREMENT_COUNT; ++i) {
    unsigned int j = i;
    while (measurements[j] < measurements[j-1] && j > 0) {
      unsigned int temp = measurements[j];
      measurements[j] = measurements[j-1];
      measurements[j-1] = temp;
      j--;
    }
  }
  
  Serial.print("Median is: ");
  if (MEASUREMENT_COUNT % 2 == 0) {
    Serial.println((measurements[MEASUREMENT_COUNT/2]+measurements[MEASUREMENT_COUNT/2-1])/2.0);
  }
  else {
    Serial.println(measurements[MEASUREMENT_COUNT/2]);
  }
}

