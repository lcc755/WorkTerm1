# WorkTerm1
A variety of examples using Arduino and Python code with the Arduino Uno and Grove Starter Kit Plus. 


All Python code that interacts with the Arduino uses the Nanpy library:
https://github.com/nanpy/nanpy

An edit to this library to make it automatically detect Windows ports, not just Ubuntu, was made.
In the SerialManager class in the serialpanager.py module:
....
    def open(self, device=None):
        '''open connection'''
        if device:
            self.device = device

        if not self.device:
+            port = list(serial.tools.list_ports.comports())
+            for p in port:
+                if "Arduino" in p[1]:
+                    name = p[0]
+                    self.device = name
+                else:
                    ports = _auto_detect_serial_unix()
                    if not len(ports):
                        raise SerialManagerError("No port was set, and no Arduino port was found!")
                    self.device = ports[0]
....



All images were created in Fritzing: http://fritzing.org/home/
