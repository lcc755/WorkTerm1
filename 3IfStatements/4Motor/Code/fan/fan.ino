int motorPin = 5;
 
void setup() { 
  pinMode(motorPin, OUTPUT); //Setup motor
  Serial.begin(9600);
  Serial.println("Set speed: 1, 2, 3 or 0(off)");
} 
 
 
void loop() { 
  if (Serial.available())   {
    
    int set = Serial.parseInt();
    
    if (set == 0) {
      Serial.println("Off");
      analogWrite(motorPin, 0);  // Off
    }
    else if (set == 1) {
      Serial.println("Slow speed set");
      analogWrite(motorPin, 75);   //Full Speed, 70 for Grove
    }
    else if (set == 2) {
      Serial.println("Medium speed set");
      analogWrite(motorPin, 165);   //Medium Speed, 120 for Grove
    }
    else if (set == 3) {
      Serial.println("Full speed set");
      analogWrite(motorPin, 255);  //Full Speed, 179 for Grove
    }
  }
} 

