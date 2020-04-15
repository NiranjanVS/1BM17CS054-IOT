
#include <SoftwareSerial.h>
#define DEBUG true 
SoftwareSerial esp8266(2,3);
SoftwareSerial mySerial(4,5);
int count = 0;
char input[12];
boolean flag = 0;     
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // esp's baud rate
  mySerial.begin(9600);
  sendData("AT+CWMODE=1\r\n",2000,DEBUG);
  sendData("AT+CWLAP\r\n",10000,DEBUG); 
  sendData("AT+CWJAP=\"accesspoint\",\"1234\"\r\n",10000,DEBUG); 
  sendData("AT+CIPMUX=0\r\n",5000,DEBUG);
  sendData("AT+CIPSTART=\"TCP\",\"192.168.4.1\",333\r\n",5000,DEBUG); 
}
 
void loop()
{
  mySerial.listen();
  if(mySerial.available())
   {
     count = 0;
     while(mySerial.available() && count < 12)
     {
       input[count] =mySerial.read();
       count++;
       delay(5);
     }
     Serial.println(input);// Print RFID tag number
     sendData("AT+CIPSTART=\"TCP\",\"192.168.4.1\",333\r\n",5000,DEBUG);
     sendData("AT+CIPSEND=12\r\n",2000,DEBUG);
     sendData(input,1000,DEBUG);
   }
}
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    esp8266.listen();
    esp8266.print(command);
    long int time = millis();
    boolean wait = false;
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        response += (char)esp8266.read();
      } 
    }
    if(debug)
    {
      Serial.print(response);
    }
   
    return response;
}
