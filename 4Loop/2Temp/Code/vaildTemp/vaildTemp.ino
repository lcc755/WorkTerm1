int red = 7;
int green = 6;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  Serial.println("Set room temp! Give a number");
}

void loop() {
  if (Serial.available()){
    digitalWrite(green, 0);
    digitalWrite(red, 0);
    
    int n = 0;  //Counter
    int number = Serial.parseInt();

    for (int i = 18; i <= 25; i++) {
      if (number == i){
        Serial.print("Temp is valid! Setting to ");
        Serial.println(number);
        digitalWrite(green, 1);
      }
      else {
        n++;
      }
    }    
    if (n == 8){  //If all possible numbers are invlid, then:
      Serial.println("Invalid number! Pick a different temp");
      digitalWrite(red, 1);
    }
  }

}
