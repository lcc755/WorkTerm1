/*
 * Info on Tone function and pitches library: 
 * https://www.arduino.cc/en/Tutorial/ToneMelody?from=Tutorial.Tone
 */

#include "pitches.h"

int speaker = A0;
int buttonC = 5;
int buttonD = 6;
int buttonE = 7;

void setup() {
  pinMode(speaker, OUTPUT);    //Setup speaker
  pinMode(buttonC, INPUT);    //Setup buttonC
  pinMode(buttonD, INPUT);    //Setup buttonD
  pinMode(buttonE, INPUT);    //Setup buttonE
}

void loop() {
    int bc = digitalRead(buttonC);  //Reading at buttonC
    int bd = digitalRead(buttonD);  //Reading at buttonD
    int be = digitalRead(buttonE);  //Reading at buttonE

    //If buttonC is pressed:
    if (bc == 1) {    
      tone(speaker, c, 20); //On the "speaker" pin, play "c" (see pitches.h), for "20" milliseconds
    }

    //If buttonD is pressed:
    else if (bd == 1) {
      tone(speaker, d, 20); //On the "speaker" pin, play "d" (see pitches.h), for "20" milliseconds
    }      

    //If buttonE is pressed:
    else if (be == 1) {
      tone(speaker, e, 20); //On the "speaker" pin, play "e" (see pitches.h), for "20" milliseconds
    }
    else{} //If no button is pressed, do nothing
}
