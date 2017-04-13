from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

motorPin = 6
button = 7

a.pinMode(motorPin, a.OUTPUT)
a.pinMode(button, a.INPUT)

while True:
    state = a.digitalRead(button)

    while (state == 1):
        for i in range(50, 255):   #Start at 50 so it doesn't stop completely at any point
            a.analogWrite(motorpin, i)
            sleep(0.03)

        for i in range(255, 50):        #Counts backwards to 50
            a.analogWrite(motorpin, i)
            sleep(0.03)  

    a.analogWrite(motorPin, 0)  #Turns off motor
