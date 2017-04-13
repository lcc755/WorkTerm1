int sensor = A0;

double readings[24];      //24 hours in a day, 1 reading every 'hour'
double B=3975;           //B value of the thermistor (Grove Starter Kit information)


void setup() {
 Serial.begin(9600);

 for (int i = 0; i < 24; i++){   //Setting up array
  readings[i] = 0;                          
 }

}

void loop() {
  double total = 0;  //Each set of readings start with a total of 0

  //Get all the readings:
  for (int i = 0; i<24; i++){              
     double reading = analogRead(sensor);  //Get reading
     double resistance= ((1023-reading)*10000/reading);  //Find resistance
     double temp= (1/(log10(resistance/10000)/B+1/298.15)-273.15);  //Convert to temperature
    
     readings[i] = temp; //Place temp reading in i space of array
     delay(100);         //Time between readings 
  }

  //Print the array:
  for (int n = 0; n<24; n++){     
    Serial.println(readings[n]);  
  }

 //Add the readings:
  for (int i = 0; i<24; i++)  {
    total += readings[i];
  }
  delay(100);
  
  //Find the average and print:
  double average = total/24;
  Serial.print("The average temp is ");
  Serial.println(average);
}
