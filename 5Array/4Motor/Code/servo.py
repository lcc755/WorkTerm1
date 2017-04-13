from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

servo = 7
arrayLen = 19

routine = [180, 0, 170, 10, 160, 20, 150, 30, 140, 40,
           130, 50, 120, 60, 110, 70, 100, 80, 90]  #pattern for servo motor

a.pinMode(servo, a.OUTPUT)

while True:
    for i in range(0, arrayLen):    #for every space in the array(forwards)
        a.analogWrite(servo, routine[i])
        sleep(0.05)            

    for i in range(arrayLen, 0):    #for every space in the array(forwards)
        a.analogWrite(servo, routine[i])      
        sleep(0.05)             
