int sensor = A0;

double readings[24];      //24 hours in a day, 1 reading every 'hour'

void setup() {
    pinMode(sensor, INPUT);
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
    double vol= (reading * (5.0/1024));   //Find resistance
    double temp = ((vol-0.5)*100);        //Convert to temperature
    
    readings[i] = temp; //Place temp reading in i space of array
    delay(100);         //Time between readings 
  } 

 //Add the readings:
  for (int i = 0; i<24; i++)  {
    total += readings[i];
  }
  
  //Find the average and print:
  double average = total/24;
  Serial.print("The average temp is ");
  Serial.println(average);
}
