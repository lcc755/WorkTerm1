from nanpy import (ArduinoApi, SerialManager)

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

sensor = 14 #Analog pin 0
led = 5

a.pinMode(sensor, a.INPUT)  #Setup sensor
a.pinMode(led, a.OUTPUT)    #Setup LED

while True:
    brightness = a.analogRead(sensor)   #Get reading
    print(brightness)
    reverse = (1023-brightness)  #For Grove, 1023 = 780
    lightRange = map(reverse, 0, 1023, 0, 255);  #For Grove, 1023 = 780. Changes the range of the readings to work with an LED
    a.analogWrite(led, lightRange)
