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

//buttons on pins 11, 12 and 13:
int br = 11;
int bg = 12;
int bb = 13;


void setup() {
  matrix.begin();  //Start up the matrix
  pinMode(br, INPUT);
  pinMode(bg, INPUT);
  pinMode(bb, INPUT);
}

void loop() {
  //Similar to if statements example
  int r = digitalRead(br);  //Get state of red button
  int g = digitalRead(bg);  //Get state of green button
  int b = digitalRead(bb);  //Get state of blue button


  if (r == HIGH) {   //If red button is pressed
    matrix.setCursor(3,8); //Start at place (1, 6)
    matrix.setTextSize(2);  //Set text size
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.print("Red");
  }
  if (g == HIGH) {
    matrix.setCursor(1,10); //Start at place (1, 6)
    matrix.setTextSize(1);  //Set text size
    matrix.setTextColor(matrix.Color333(0,7,0));
    matrix.print("Green");
  }
  if (b == HIGH) {
    matrix.setCursor(1,8); //Start at place (1, 6)
    matrix.setTextSize(2);  //Set text size
    matrix.setTextColor(matrix.Color333(0,0,1));
    matrix.print("Blue");
  }
  else {
    matrix.fillScreen(matrix.Color333(0, 0, 0));    //Clear board
  } 
}
