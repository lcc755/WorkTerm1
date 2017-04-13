
int motorPin = 6;
int button = 7;

void setup() { 
  pinMode(motorPin, OUTPUT);
  pinMode(button, INPUT);
} 
 
 
void loop() { 
  int state = digitalRead(button);
  
  while (state == 1){
      for (int i=50; i<=255; i++){  //Start at 50 so it doesn't stop completely at any point
        analogWrite(motorPin, i); 
        delay(30);
      }
      
      for (int i=255; i>=50; i--){    //Counts backwards to 50
        analogWrite(motorPin, i); 
        delay(30);
      }
  }
  
  analogWrite(motorPin, 0); //Turns off motor
}
