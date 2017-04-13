int sensor = A0;

void setup(){
   pinMode(sensor, INPUT);    //Setup sensor
   Serial.begin(9600);    //Set computer serial output to 9600 bits per second(make sure manager is the same)
    
   Serial.println("Angle is:  ");
}

void loop(){
    int reading = analogRead(sensor);  //Get reading
    int angle = map(reading, 1, 1023, 0, 360);  //Convert reading to degrees(0 to 360)
    
    Serial.println(angle); 
    delay(1000); 
}
