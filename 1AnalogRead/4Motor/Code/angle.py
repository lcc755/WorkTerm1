from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #Analog pin 0
a.pinMode(sensor, a.INPUT)  #Setup sensor

print("Angle is:  ")

while True:
    reading = analogRead(sensor)      #Get reading
    angle = map(reading, 0, 1023, 0, 360)   #Convert reading to degrees(0 to 360)
    
    print(angle)
    sleep(1)
