#Conversion information from Arduino documentations
#Resistor calculations: http://www.mouser.com/catalog/specsheets/Seeed_101020022.pdf

from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #Analog pin 0
a.pinMode(sensor, a.INPUT)     #Setup sensor

print("Sensor resistance is:  ")

while True:
    brightness = a.analogRead(sensor)  #Get reading
    resistance =(1023-brightness)*10/brightness   #Resistance of sensor
    
    print(resistance)
    time.sleep(5)
