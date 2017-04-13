
int ledPins[] = {4, 5, 6};
int numPins = 3;

int p1[] = {1, 0, 1};
int p2[] = {0, 1, 0};

void setup() {
    for (int i = ledPins[0]; i < numPins; i++) {
      pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
  
  for (int i = ledPins[0]; i < numPins; i++){
    digitalWrite(ledPins[i], p1[i]);   //Led i with pattern 1
    delay(100);
  }
  for (int i = 0; ledPins[0] < numPins; i++){
    digitalWrite(ledPins[i], p2[i]);   //Led i with pattern 2
    delay(100);          
  }
}
