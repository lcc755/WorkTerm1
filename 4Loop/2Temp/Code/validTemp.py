from nanpy import SerialManager, ArduinoApi

#Connect to Arduino. Automatically finds serial port.
connection = SerialManager()
a = ArduinoApi(connection=connection)

red = 7
green = 6

print("Set room temp! Give a number")

a.pinMode(red, a.OUTPUT)
a.pinMode(green, a.OUTPUT)

while True:
    n = 0 #Counter
    number = raw_input(">")
    
    a.digitalWrite(green, 0)
    a.digitalWrite(red, 0)
    
    for i in range(18, 25):
        if (i == number):
            print("Temp is valid! Setting to ")
            print(number)
            a.digitalWrite(green, 1)

        else:
            n += 1

    if (n == 8):   #If all possible numbers are invlid, then:
        print("Invalid number! Pick a different temp")
        a.digitalWrite(red, 1)
