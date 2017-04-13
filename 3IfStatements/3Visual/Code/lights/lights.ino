int red = 5;
int yellow = 6;
int green = 7;

int br = 2;
int by = 3;
int bg = 4;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(br, INPUT);
  pinMode(by, INPUT);
  pinMode(bg, INPUT);
}

void loop() {
  int r = digitalRead(br);  //Get state of red button
  int y = digitalRead(by);  //Get state of yellow button
  int g = digitalRead(bg);  //Get state of green button

  if (r == HIGH) {   
    digitalWrite(red, HIGH);  //Turn on red LED
  }
  if (y == HIGH) {
    digitalWrite(yellow, HIGH); //Turn on yellow LED
  }
  if (g == HIGH) {
    digitalWrite(green, HIGH);  //Turn on green LED
  }
  else {
    digitalWrite(red, LOW); //Turn off red LED
    digitalWrite(yellow, LOW);  //Turn off yellow LED
    digitalWrite(green, LOW); //Turn off green LED
  }
}
