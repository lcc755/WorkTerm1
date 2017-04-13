int sensor = A0;
int motorPin = 5;

void setup() {
  pinMode(sensor, INPUT);      //Setup sensor
  pinMode(motorPin, OUTPUT);   //Setup motor
  Serial.begin(9600); //Set computer serial output to 9600 bits per second(make sure manager is the same)
}

void loop() {
    int reading = analogRead(sensor);  //Get reading
    int angle = map(reading, 0, 1023, 0, 360);  //Convert reading to degrees by changing the range
    int speed = map(angle, 0, 360, 0, 255);     //Find speed relative to angle
    
    analogWrite(motorPin, angle);
}
