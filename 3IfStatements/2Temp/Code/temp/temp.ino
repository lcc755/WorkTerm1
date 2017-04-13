
int sensor = A0;

int red = 6;
int green = 7;

void setup() {
  pinMode(sensor, INPUT); //Setup sensor
  pinMode(red, OUTPUT);   //Setup red LED
  pinMode(green, OUTPUT); //Setup red LED
}

void loop() {
  
   double reading = analogRead(sensor); //Get reading
   double vol= (reading * (5.0/1024));    //Find relative voltage
   double temp = ((vol-0.5)*100);   //Find temp

   //If temp is out of comfortable range:
   if (temp<20.0 || temp>24.0 ) {  
      digitalWrite(red, HIGH);   //Turn on red light
      digitalWrite(green, LOW);  //Turn off green light
  }
  
  //If temp is in comfortable range:
  else if (20.0<temp && temp<25.0) {
      digitalWrite(green, HIGH);  //Turn on green light
      digitalWrite(red, LOW);     //Turn off red light
  }

}
