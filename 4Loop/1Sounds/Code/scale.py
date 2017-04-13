#Info on Tone function and pitches library: 
#https://www.arduino.cc/en/Tutorial/ToneMelody?from=Tutorial.Tone

#Range CAN be approx. 0-5000

from nanpy import (ArduinoApi, SerialManager, Tone)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
 
speaker = 5
tone = Tone(speaker, connection)
a = ArduinoApi(connection)

a.pinMode(speaker, a.OUTPUT)    #Setup speaker pin

while True:
        for i in range(300, 1650[, 50]):      #For ever 50 tones from 300 to 1650 (forwards)
                tone.play(i, 1) #Play tone i
                sleep(0.1)

        for i in range(1650, 300[, 50]):      #For ever 50 tones from 1650 to 30 (backwards)
                tone.play(i, 1) #Play tone i
                sleep(0.1)
