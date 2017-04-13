int sensor = A0;

void setup() {
  pinMode(sensor, INPUT);  //Setup sensor
  Serial.begin(9600);   //Set computer serial output to 9600 bits per second(make sure manager is the same)
}

void loop() {
  double reading = analogRead(sensor);  //Get reading
  double vol= (reading * (5.0/1024)); //Relative voltage
  double temp = ((vol-0.5)*100);  //Find temp

  Serial.println(temp);
  delay(1000);
}
