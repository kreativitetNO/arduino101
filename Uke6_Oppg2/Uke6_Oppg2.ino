const int POT_PIN = A0;
const int MEASUREMENT_COUNT = 50;
const int MEASUREMENT_INTERVAL = 250;

struct Measurement {
  int data;
  unsigned long time;
};

Measurement measurements[MEASUREMENT_COUNT];

void outputSum();
void outputAverage();
void outputMinMax();
void outputMedian();

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < MEASUREMENT_COUNT; ++i) {
    measurements[i].time = millis();
    measurements[i].data = analogRead(POT_PIN);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(measurements[i].data);
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
    sum += measurements[i].data;
  }
  Serial.print("Sum of measurements: ");
  Serial.println(sum);
}

void outputAverage() {
  unsigned long sum = 0;
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    sum += measurements[i].data;
  }
  Serial.print("Average measurement: ");
  Serial.println(1.0*sum/MEASUREMENT_COUNT);
}

void outputMinMax() {
  unsigned int minValue = 1023;
  unsigned int maxValue = 0;
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    minValue = min(measurements[i].data, minValue);
    maxValue = max(measurements[i].data, maxValue);
  }
  Serial.print("Min: ");
  Serial.println(minValue);
  Serial.print(" @: ");
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    if (measurements[i].data == minValue) {
      Serial.print(measurements[i].time);
      Serial.print(" ");
    }
  }
  Serial.println();
  Serial.print("Max: ");
  Serial.println(maxValue);
  Serial.print(" @: ");
  for (unsigned int i = 0; i < MEASUREMENT_COUNT; ++i) {
    if (measurements[i].data == maxValue) {
      Serial.print(measurements[i].time);
      Serial.print(" ");
    }
  }
  Serial.println();
}

void outputMedian() {
  // Insertion sort - see Wikipedia
  for (unsigned int i = 1; i < MEASUREMENT_COUNT; ++i) {
    unsigned int j = i;
    while (measurements[j].data < measurements[j-1].data && j > 0) {
      Measurement temp = measurements[j];
      measurements[j] = measurements[j-1];
      measurements[j-1] = temp;
      j--;
    }
  }
  
  Serial.print("Median: ");
  if (MEASUREMENT_COUNT % 2 == 0) {
    Serial.println((measurements[MEASUREMENT_COUNT/2].data+measurements[MEASUREMENT_COUNT/2-1].data)/2.0);
  }
  else {
    Serial.println(measurements[MEASUREMENT_COUNT/2].data);
  }
}

