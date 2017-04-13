int red = 3;
int yellow = 5;
int green = 6;

void setup() {
  pinMode(red, OUTPUT);   //Setup red LED
  pinMode(yellow, OUTPUT);  //Setup yellow LED
  pinMode(green, OUTPUT);   //Setup green LED
}

void loop() {
    digitalWrite(red, 1);  //Turn on red LED
    delay(500);   //Wait half a second
    digitalWrite(yellow, 1);  //Turn on yellow LED
    delay(500);   //Wait half a second
    digitalWrite(green, 1); //Turn on green LED
    delay(500);     //Wait half a second
    
    digitalWrite(red, 0);     //Turn off red LED
    digitalWrite(yellow, 0);  //Turn off yellow LED
    digitalWrite(green, 0);   //Turn off green LED
    
    delay(1000);
}
