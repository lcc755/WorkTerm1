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

int sensor = A5; //Rotary angle sensor
int button = 11;

//Starting x and y coordinates:
int y = 1;  
int x = 1;

void setup() {
  matrix.begin();  //Start up the matrix
  pinMode(sensor, INPUT);      //Setup sensor
  pinMode(button, OUTPUT);   //Setup motor
}

void loop() {
  int reading = analogRead(sensor);  //Get reading
  int pixel = map(reading, 0, 1023, 0, 32);  //Convert reading to pixel number by changing the range

  int state = digitalRead(button);

  //If button is not pressed, control x 
  if (state == 0) {
    matrix.drawPixel(pixel, y, matrix.Color333(random(0, 7), random(0, 7), random(0, 7)));
    x = pixel;
  }
  //If button is pressed, control y
  if (state == 1) {
    matrix.drawPixel(x, pixel, matrix.Color333(random(0, 7), random(0, 7), random(0, 7)));
    y = pixel;
  }
  
}

