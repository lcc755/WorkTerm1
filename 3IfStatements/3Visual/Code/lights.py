from nanpy import SerialManager, ArduinoApi
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection)

red = 5
yellow = 6
green = 7

a.pinMode(red, a.OUTPUT)  #Setup red LED
a.pinMode(yellow, a.OUTPUT)  #Setup yellow LED
a.pinMode(green, a.OUTPUT)  #Setup green LED

br = 2
by = 3
bg = 4

a.pinMode(br, a.INPUT)  #Setup red button
a.pinMode(by, a.INPUT)  #Setup yellow button
a.pinMode(bg, a.INPUT)  #Setup green button


while True:
    r = a.digitalRead(br)   #Get state of red button
    y = a.digitalRead(by)   #Get state of yellow button
    g = a.digitalRead(bg)   #Get state of green button

    if r == 1:
        a.digitalWrite(red, 1)    #Turn on red LED
        
    if y == 1:
        a.digitalWrite(yellow, 1)    #Turn on yellow LED
            
    if g == 1:
        a.digitalWrite(green, 1)    #Turn on green LED

    else:
        a.digitalWrite(red, 0)    #Turn off red LED
        a.digitalWrite(yellow, 0)    #Turn off yellow LED
        a.digitalWrite(green, 0)    #Turn off green LED
