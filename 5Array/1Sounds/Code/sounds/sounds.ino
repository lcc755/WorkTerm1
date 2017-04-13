/*
 * Tone and notes were found at: https://www.arduino.cc/en/reference/tone
 */

#include "melody.h";

int speaker = 5;
int button = 7;

//Twinkle Twinkle Little Star notes. Can be minimized and hidden in header file. 
//Header file can also be changed so that used notes are simply "c", "d", etc.
int melody[] =   { NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5,
                   NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5,
                   NOTE_D5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5,
                   NOTE_E5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5,
                   NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5,
                   NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
                   NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5 };
                   
//Duration for each note. Can be minimized and hidden in header file.
int Durations[] = { 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2,
                  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 1};
                  
void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  int stat = digitalRead(button);  //Get reading

  if (stat == 1){   //If button is pressed
    
    for (int i=0; i <= (sizeof(melody)/2); i++){  //Go though notes in melody
      int noteDuration = 1000/Durations[i];
      tone(speaker, melody[i], noteDuration); //On the speaker pin, play melody[i], for the noteDuration

      delay(noteDuration);    //Pause helps create a smooth transition
    }
    noTone(speaker);
  }

}
