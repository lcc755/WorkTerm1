from nanpy import (ArduinoApi, SerialManager, Tone)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()

speaker = 14  #AO on Arduino
tone = Tone(speakerpin, connection)     #Setting "tone" to mean using the "speaker" pin on the "connection". See tone library in Nanpy 
a = ArduinoApi(connection)

buttonC = 5
buttonD = 6
buttonE = 7

#Definitions for notes are in tone library in Nanpy, can easily change names to simply "c", "d", etc. if needed
c = Tone.NOTE_C6  
d = Tone.NOTE_D6
e = Tone.NOTE_E6

a.pinMode(speaker, a.OUTPUT)        #Setup speaker pin
a.pinMode(buttonC, a.INPUT)         #Setup buttonC
a.pinMode(buttonD, a.INPUT)         #Setup buttonD
a.pinMode(buttonE, a.INPUT)         #Setup buttonE

while True:
        bc = a.digitalRead(buttonC)     #Reading at buttonC
        bd = a.digitalRead(buttonD)     #Reading at buttonD
        be = a.digitalRead(buttonE)     #Reading at buttonE

        #If buttonC is pressed:
        if (bc == 1):
                tone.play(c, 1) #Play note c

        #If buttonD is pressed:
        elif (bd == 1):
                tone.play(d, 1) #Play note d

        #If buttonE is pressed:
        elif (be == 1):
                tone.play(e, 1) #Play note e

        tone.stop(      #Stop note
