/*
 * Info on Tone function and pitches library: 
 * https://www.arduino.cc/en/Tutorial/ToneMelody?from=Tutorial.Tone
 * 
 * Range CAN be approx. 0-5000
 * 
 */

int speaker = 5;

void setup() {
  pinMode(speaker, OUTPUT);  //Setup speaker pin
}

void loop() {
    
   for (int i=300; i<1650; i += 50){  //For ever 50 tones from 300 to 1650 (forwards)
      tone(speaker, i, 1000);  //On the "speaker" pin, play "i", for "1000" milliseconds
      delay(100);
    }
    for (int i=1550; i>300; i -= 50){  
      tone(speaker, i, 1000);   //On the "speaker" pin, play "i", for "1000" milliseconds
      delay(100);
    }
}
