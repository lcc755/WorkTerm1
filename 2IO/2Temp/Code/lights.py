from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

red = 3
yellow = 5
green = 6

a.pinMode(red, a.OUTPUT)    #Setup red LED
a.pinMode(yellow, a.OUTPUT) #Setup yellow LED
a.pinMode(green, a.OUTPUT)  #Setup green LED


while True: 
    a.digitalWrite(red, 1)  #Turn on red LED
    sleep(0.5)      #Wait half a second
    a.digitalWrite(yellow, 1)   #Turn on yellow LED
    delay(0.5)      #Wait half a second
    a.digitalWrite(green, 1)    #Turn on green LED
    sleep(0.5)      #Wait half a second
    
    digitalWrite(red, 0)        #Turn off red LED
    digitalWrite(yellow, 0)     #Turn off yellow LED
    digitalWrite(green, 0)      #Turn off green LED
    
    sleep(1)
