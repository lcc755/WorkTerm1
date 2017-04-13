from nanpy import (ArduinoApi, SerialManager)
from time import sleep

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection=connection)

motor = 5

a.pinMode(motor, OUTPUT)  #Setup motor

print("1 for on, 0 for off")

while True:
    speed = raw_input("> ")
    
    if (speed == "0"):
        print("Off");
        analogWrite(motorPin, 0)  #Off
      
    elif (speed == "1"):
        print("Slow speed set")
        analogWrite(motorPin, 75) #Full Speed, 70 for Grove
    
    elif (speed == "2"):
        print("Medium speed set")
        analogWrite(motorPin, 165)    #Medium Speed, 120 for Grove
    
    elif (speed == "3"):
        Serial.println("Full speed set")
        analogWrite(motorPin, 255)    #Full Speed, 179 for Grove

