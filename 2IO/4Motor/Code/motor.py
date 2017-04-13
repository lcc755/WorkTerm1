from nanpy import (ArduinoApi, SerialManager, Tone)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection=connection)

sensor = 14 #Analog pin 0
motorPin = 5

a.pinMode(sensor, a.INPUT)  #Setup sensor
a.pinMode(motorPin, a.OUTPUT) #Setup motor

while True:
    reading = analogRead(sensor)    #Get reading
    angle = map(reading, 0, 1023, 0, 360) #Convert reading to degrees by changing the range
    speed = map(angle, 0, 360, 0, 255)    #Find speed relative to angle

    a.analogWrite(motorPin, speed)
