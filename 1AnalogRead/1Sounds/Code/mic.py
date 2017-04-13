#Conversion information: https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels

from nanpy import (ArduinoApi, SerialManager)
from time import sleep, time

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection = connection)

mic = 14 #Analog pin 0
 
a.pinMode(mic, a.INPUT)   #Setup mic sensor

while True:
    signalMax = 0;
    signalMin = 1024;
    startTime = time.time() * 1000;  #Start time in milliseconds

    while ((time.time() * 1000) - startTime < 50):  #Over 50 milliseconds

        reading = a.analogRead(mic)

        if (reading < 1024):    
            if (reading > signalMax):    #If reading is higher than max, set it as max
                signalMax = reading
            elif (reading < signalMin):   #If reading is higher than min, set it as min
                signalMin = reading

    peakToPeak = signalMax - signalMin      #Find peak to peak reading
    volts = (peakToPeak * 5.0) / 1024       #Find voltage

    print (volts)
    time.sleep(0.55)
