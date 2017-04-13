from nanpy import Tone, SerialManager, ArduinoApi
from time import sleep

#Connect to Arduino. Automatically finds serial port
connection = SerialManager()
a = ArduinoApi(connection)

speaker = 5
button = 7

tone = Tone(speaker, connection)
a.pinMode(button, a.INPUT)

#Twinkle Tiwnkle Little Star notes. Can be simplified and hidden in multiple ways in a Module. 
#Can also seperate notes and duration into 2 seperate arrays.
#Header file can also be changed so that used notes are simply "c", "d", etc.
melody =   [[Tone.NOTE_C5, 4], [Tone.NOTE_C5, 4], [Tone.NOTE_G5, 4],
            [Tone.NOTE_G5, 4], [Tone.NOTE_A5, 4], [Tone.NOTE_A5, 4],
            [Tone.NOTE_G5, 4], [Tone.NOTE_F5, 3], [Tone.NOTE_F5, 4],
            [Tone.NOTE_E5, 4], [Tone.NOTE_E5, 4], [Tone.NOTE_D5, 4],
            [Tone.NOTE_D5, 4], [Tone.NOTE_C5, 4], [Tone.NOTE_G5, 2],
            [Tone.NOTE_G5, 4], [Tone.NOTE_F5, 4], [Tone.NOTE_F5, 4],
            [Tone.NOTE_E5, 4], [Tone.NOTE_E5, 4], [Tone.NOTE_D5, 4], 
            [Tone.NOTE_G5, 3], [Tone.NOTE_G5, 4], [Tone.NOTE_F5, 4],
            [Tone.NOTE_F5, 4], [Tone.NOTE_E5, 4], [Tone.NOTE_E5, 4],
            [Tone.NOTE_D5, 4], [Tone.NOTE_C5, 2], [Tone.NOTE_C5, 4],
            [Tone.NOTE_G5, 4], [Tone.NOTE_G5, 4], [Tone.NOTE_A5, 4],
            [Tone.NOTE_A5, 4], [Tone.NOTE_G5, 4], [Tone.NOTE_F5, 2],
            [Tone.NOTE_F5, 4], [Tone.NOTE_E5, 4], [Tone.NOTE_E5, 4],
            [Tone.NOTE_D5, 4], [Tone.NOTE_D5, 4], [Tone.NOTE_C5, 4], [0, 2]]


while True:

    state = a.digitalRead(button)   #Get reading

    if (state == 1):     #If button is pressed
        for note in melody:     #Go though notes in melody
            noteDuration = 1000/note[1]
            tone.play(note[0] , noteDuration)  #note and duration
            
            sleep(noteDuration)

        tone.stop()
