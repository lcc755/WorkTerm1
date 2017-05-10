#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

//The following is necessary for the matrix, however, it can be placed in a header file for simplicity for the students 
#define CLK 8 
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

//Sound sensor on pin A5:
int mic = A0;


void setup() {
  matrix.begin();  //Start up the matrix
  pinMode(mic, INPUT);
}

void loop() {
  //Conversion as used in the first exmple (AnalogRead):
  int signalMax = 0;
   int signalMin = 1024;
   long startMillis= millis();  //Start time

   while (millis() - startMillis < 50) {     //Over 50 milliseconds
      double reading = analogRead(mic);
      
      if (reading < 1024)  {
         if (reading > signalMax) {   
            int signalMax = reading;   //If reading is higher than max, set it as max
         }
         else if (reading < signalMin) {   
            signalMin = reading;     //If reading is higher than min, set it as min
         }
      }
   }
   int peakToPeak = signalMax - signalMin;  //Find peak to peak reading
   double volts = (peakToPeak * 5.0) / 1024;    //Find voltage

  //***********************************************************************************//
  matrix.setCursor(1,1); //Start at place (1, 1)
  matrix.setTextSize(1);  //Set text size
  matrix.setTextColor(matrix.Color333(5,2,5));  //Set text color in terms of RGB (red, green, blue)
  matrix.print("Volt");  //Print "Temp" on matrix. This will use the space, size and color previously definied. 

  //The same set up is followed for the next line. The Y cordinates move to 10 since font 1 has a height of 8 pixels. 
  matrix.setCursor(1,10); 
  matrix.setTextSize(1);  
  matrix.setTextColor(matrix.Color333(5,2,5));
  matrix.print("is:");

  matrix.setCursor(1,20); 
  matrix.setTextSize(1);  
  matrix.setTextColor(matrix.Color333(random(1,6),random(1,6),random(1,6)));   //Random color to make it more interesting
  matrix.print(volts);    //Print the voltage

  delay(1000);    //Wait a second
  matrix.fillScreen(matrix.Color333(0, 0, 0));    //Reset board 
}

