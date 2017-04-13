int red = 3;
int yellow = 5;
int green = 6;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  
  for (int i = red; i <= green; i++){   //starting with the red pin, go through until it reaches the green
    if (i != 4) {   //pin 4 is not used since not a PWM pin
      for (int n = 0; n <= 1023; n += 4){  
        analogWrite(i, n);  //Write n to i 
        delay(30);
    }
  }
  analogWrite(i, 0);  //Turn off LED
  delay(50);
 }
}
