#Conversions from: http://wiki.seeed.cc/Grove_Starter_Kit_Plus/

from nanpy import (ArduinoApi, SerialManager)
from time import sleep
import math

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #A0 on shield
B = 3975  #B value of the thermistor (Grove Starter Kit information)

a.pinMode(sensor, a.INPUT)  #Setup sensor

while True:
    total = 0   #Each set of readings start with a total of 0

    #Get all the readings:
    for i in range(0, 24):
        reading = a.analogRead(sensor)                #Get reading
        resistance = ((1023-reading)*10000/reading)   #Find resistance
        log = math.log10(resistance/10000)
        temp = (1/(log/B+1/298.15)-273.15)            #Find temperature

        readings[i] = temp  #Place temp reading in i space of array
        sleep(0.1)          #Time between readings 

    #Add the readings:
    for i in range(0, 24):
        total += readings[i]

    #Find the average and print:
    average = total/24
    print("The average temp is ")
    print(average)
    

