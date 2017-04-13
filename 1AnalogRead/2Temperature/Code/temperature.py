from nanpy import (ArduinoApi, SerialManager)
from time import sleep

connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #Analog pin 0
 
a.pinMode(sensor, a.INPUT)  #Setup sensor

while True:
    
    reading = a.analogRead(sensor)  #get reading
    vol = (reading*(5.0/1024))    #relative voltage
    temp = ((vol-0.5)*100)   #find temp

    print (temp)
    sleep(1)
