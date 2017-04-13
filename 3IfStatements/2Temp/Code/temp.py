from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection=connection)

sensor = 14  #AO on Arduino
red = 6
green = 7

a.pinMode(sensor, a.INPUT)  #Setup sensor
a.pinMode(red, a.OUTPUT)    #Setup red LED
a.pinMode(green, a.OUTPUT)  #Setup red LED

while True:
    
    reading = a.analogRead(sensor)  #Get reading
    vol = (reading * (5.0/1024))        #Find relative voltage
    temp = ((vol-0.5)*100)              #Find temp

   #If temp is out of comfortable range:
    if ((temp < 20.0) |(temp > 24.0)):
      a.digitalWrite(red, 1)    #Turn on red light
      a.digitalWrite(green, 0)  #Turn off green light

    #If temp is in comfortable range:
    elif ((20.0 < temp) & (temp < 25.0)): 
      a.digitalWrite(green, 1)  #Turn on green light
      a.digitalWrite(red, 0)    #Turn off red light
