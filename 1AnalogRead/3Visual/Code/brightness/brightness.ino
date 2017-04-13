/*
 * Conversion information from Arduino documentations
 * Resistor calculations: http://www.mouser.com/catalog/specsheets/Seeed_101020022.pdf
 */

int sensor = A0;

void setup() {
   pinMode(sensor, INPUT);  //Setup sensor
   Serial.begin(9600); //Set computer serial output to 9600 bits per second(make sure manager is the same)
  
   Serial.println("Sensor resistance is:  ");
}
 
void loop() {
   double brightness = analogRead(sensor);     //Get reading
   double resistance = (1023-brightness)*10/brightness;   //Resistance of sensor
   
   Serial.println(resistance);
   delay(1000);
}
