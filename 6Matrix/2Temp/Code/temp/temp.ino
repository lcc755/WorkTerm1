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

//Temperature sensor on pin A5:
int tempSensor = A5;


void setup() {
  matrix.begin();  //Start up the matrix
  pinMode(tempSensor, INPUT);
}

void loop() {
  //Conversion as used in previous exmples:
  double reading = analogRead(tempSensor);  
  double vol= (reading * (5.0/1024)); 
  double temp = ((vol-0.5)*100);

  matrix.setCursor(1,1); //Start at place (1, 1)
  matrix.setTextSize(1);  //Set text size
  matrix.setTextColor(matrix.Color333(5,2,5));  //Set text color in terms of RGB (red, green, blue)
  matrix.print("Temp");  //Print "Temp" on matrix. This will use the space, size and color previously definied. 

  //The same set up is followed for the next line. The Y cordinates move to 10 since font 1 has a height of 8 pixels. 
  matrix.setCursor(1,10); 
  matrix.setTextSize(1);  
  matrix.setTextColor(matrix.Color333(5,2,5));
  matrix.print("is:");

  //Set up temperature printing:
  matrix.setCursor(1,20); 
  matrix.setTextSize(1);  

  //Temperature color is..
  if (temp<20.0) {
      matrix.setTextColor(matrix.Color333(0,0,7));   //Blue if lower than 20 (cold)
  }
  else if (20.0<temp && temp<25.0) {
      matrix.setTextColor(matrix.Color333(0,7,0));   //Green if between 20 and 25 (comfortable)
  }
  else if (temp>24.0) {
      matrix.setTextColor(matrix.Color333(7,0,0));   //Red if above 25 (hot)
  }
   
  matrix.print(temp);    //Print the temperature

  delay(1000);    //Wait a second
  matrix.fillScreen(matrix.Color333(0, 0, 0));    //Reset board 
}

