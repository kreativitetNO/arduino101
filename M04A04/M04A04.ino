unsigned long factorial(int);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int input = Serial.parseInt();
    Serial.print("The factorial of ");
    Serial.print(input);
    Serial.print(" is: ");
    Serial.println(factorial(input));
  }
}

unsigned long factorial(int n) {
  if (n < 2)
    return 1;
  if (n > 13) {
    Serial.println("Number is too large.");
    return 0;
  }
  unsigned long result = 1;
  for (int i = 2; i <= n; ++i)
    result *= i;
  return result; 
}

