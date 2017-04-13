/*
 * Some note values: C = 1047, D = 1175, E = 1319
 */

int speaker = A0;
int note = 1047;   //Set as C

void setup() {
  pinMode(speaker, OUTPUT);  //Setup speaker
}

void loop() {
  tone(speaker, note, 20);  //On the "speaker" pin, play the "note", for a duration of "20" milliseconds
}
