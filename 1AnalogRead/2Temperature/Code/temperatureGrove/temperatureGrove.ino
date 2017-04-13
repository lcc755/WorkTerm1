/*
 * Conversions from: http://wiki.seeed.cc/Grove_Starter_Kit_Plus/
 */

double sensor = A0;
double B=3975;           //B value of the thermistor (Grove Starter Kit information)

void setup() {
  pinMode(sensor, INPUT);  //Setup sensor
  Serial.begin(9600);  //Set computer serial output to 9600 bits per second(make sure manager is the same)
}

void loop() {
  double reading = analogRead(sensor);    //Get reading
  double resistance= ((1023-reading)*10000/reading);    //Find resistance
  double temp= (1/(log10(resistance/10000)/B+1/298.15)-273.15);        //Convert to temperature

  Serial.println(temp);
  delay(1000);
}

