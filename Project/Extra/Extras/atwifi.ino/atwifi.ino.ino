
#include <SoftwareSerial.h>

SoftwareSerial wifi(2,3); // RX | TX

SoftwareSerial mySerial(5,6);
int count = 0;                                          // count = 0
char input[12];                                         // character array of size 12 
boolean flag = 0; 
void setup()
{

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  wifi.begin(9600);  // HC-05 default speed in AT command more
  mySerial.begin(9600);
 // wifi.listen();
 // wifi.println("AT\r");
 // wifi.println("AT+")
 
  
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  //wifi.listen();
   if(wifi.available()){
    Serial.write(wifi.read());}

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available()){
    
    wifi.listen();
    wifi.write(Serial.read());}
   /* mySerial.listen();
     if(mySerial.available())
   {
      count = 0;
      while(mySerial.available() && count < 12)          // Read 12 characters and store them in input array
      {
         input[count] =mySerial.read();
         count++;
         delay(5);
      }
      Serial.print(input);                             // Print RFID tag number 
      
         }*/
}
