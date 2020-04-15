
#include <SoftwareSerial.h>

SoftwareSerial wifi(2,3); // RX | TX

void setup()
{

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  wifi.begin(9600);  // HC-05 default speed in AT command more
  
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  //wifi.listen();
   if(wifi.available()){    Serial.write(wifi.read());   }

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available()){  wifi.write(Serial.read());   }

}
