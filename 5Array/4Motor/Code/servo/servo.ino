int servo = 7;
int arrayLen = 19;

int routine[] = {180, 0, 170, 10, 160, 20, 150, 30, 140, 40, 
                  130, 50, 120, 60, 110, 70, 100, 80, 90};    //pattern for servo motor

void setup() {
  pinMode(servo, OUTPUT);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (int i = 0; i < arrayLen; i++) {  //for every space in the array(forwards)
    analogWrite(servo, routine[i]);       
    delay(50);             
  }
  for (int i = arrayLen; i > 0; i--) {  //for every space in the array(forwards)
    analogWrite(servo, routine[i-1]);       
    delay(50);             
  }
}

