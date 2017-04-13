int sensor = A0;
int led = 5;

void setup() {
  pinMode(sensor, INPUT);  //Setup sensor
  pinMode(led, OUTPUT);  //Setup LED
  Serial.begin(9600); //Set computer serial output to 9600 bits per second(make sure manager is the same)
}
 
void loop() {
   int brightness = analogRead(sensor);  //Get reading
   Serial.println(brightness); 
   int reverse = (1023-brightness);            //For Grove, 1023 = 780. More  light = higher reading, therefore need reverse
   int range = map(reverse, 0, 1023, 0, 255);  //For Grove, 1023 = 780. Changes the range of the readings to work with an LED 
   analogWrite(led, range);
}
