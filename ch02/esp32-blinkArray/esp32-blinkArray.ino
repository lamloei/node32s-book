int a[] = {23,22,21,19,18,5,17,16,4,0,2,15,13,12,14,27,26,25,33,32};

void setup() {
  for (int i=0; i < (sizeof(a)/sizeof(int)); i++) {
    digitalWrite(a[i], HIGH);
  }
  for (int i=0; i < (sizeof(a)/sizeof(int)); i++) {
    pinMode(a[i], OUTPUT);
  }
}

void loop() {
  for (int i=0; i < (sizeof(a)/sizeof(int)); i++) {
    digitalWrite(a[i], LOW);
    delay(300);
    digitalWrite(a[i], HIGH);
    delay(300);
  }
}
