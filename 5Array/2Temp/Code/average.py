from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #Analog pin 0
 
a.pinMode(sensor, a.INPUT)  #Setup sensor

while True:
    total = 0   #Each set of readings start with a total of 0

    #Get all the readings:
    for i in range(0, 24):
        reading = a.analogRead(sensor)  #get reading
        vol = (reading*(5.0/1024))    #relative voltage
        temp = ((vol-0.5)*100)   #find temp
        
        readings[i] = temp  #Place temp reading in i space of array
        sleep(0.1)          #Time between readings 

    #Add the readings:
    for i in range(0, 24):
        total += readings[i]

    #Find the average and print:
    average = total/24
    print("The average temp is ")
    print(average)
