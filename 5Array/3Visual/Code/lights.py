from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

ledPins = [4, 5, 6]
numPins = 3

p1 = {1, 0, 1}
p2 = {0, 1, 0}

for i in range(ledPins[0], numPins):
    a.pinMode(ledPins[i], a.OUTPUT)

while True:
    for i in range(ledPins[0], numPins):
        a.digitalWrite(ledPins[i], p1[i])   #Led i with pattern 1
        sleep(0.01)
        
    for i in range(ledPins[0], numPins):
        a.digitalWrite(ledPins[i], p2[i])     #Led i with pattern 2
        sleep(0.01)  
