from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection=connection)

red = 3;
yellow = 5;
green = 6;

a.pinMode(red, OUTPUT)
a.pinMode(yellow, OUTPUT)
a.pinMode(green, OUTPUT)


while True:

    for i in range(red, green):  #starting with the red pin, go through until it reaches the green
        if (i != 4):        #pin 4 is not used since not a PWM pin
            for n in range(0, 1023, 4):
                a.analogWrite(i, n)     #Write n to i 
                sleep(0.03)
            analogWrite(i, 0);  #Turn off LED
        sleep(0.05)
