#Some note values: C = 1047, D = 1175, E = 1319

from nanpy import (ArduinoApi, SerialManager, tone)

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()

speaker = 14 #Analog pin 0
tone = Tone(speaker, connection)    #Setting "tone" to mean using the "speaker" pin on the "connection". See tone library in Nanpy 

note = 1047  #On the "speaker" pin, play the "note", for a duration of "20" milliseconds

con.pinMode(speaker, a.OUTPUT)  #Setup speaker

while True:
    tone.play(note, 1)  #Play "note" 
