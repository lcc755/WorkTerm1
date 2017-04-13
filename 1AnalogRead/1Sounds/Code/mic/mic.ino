/*
 * Conversion information: https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels
 */

int mic = A0;

void setup() {
   pinMode(mic, INPUT);  //Setup mic sensor
   Serial.begin(9600); //Set computer serial output to 9600 bits per second(make sure manager is the same)
}
 
void loop() {
   int signalMax = 0;
   int signalMin = 1024;
   long startMillis= millis();  //Start time

   while (millis() - startMillis < 50) {     //Over 50 milliseconds
      double reading = analogRead(mic);
      
      if (reading < 1024)  {
         if (reading > signalMax) {   
            int signalMax = reading;   //If reading is higher than max, set it as max
         }
         else if (reading < signalMin) {   
            signalMin = reading;     //If reading is higher than min, set it as min
         }
      }
   }
   int peakToPeak = signalMax - signalMin;  //Find peak to peak reading
   double volts = (peakToPeak * 5.0) / 1024;    //Find voltage
 
   Serial.println(volts);
   delay(500);
}
