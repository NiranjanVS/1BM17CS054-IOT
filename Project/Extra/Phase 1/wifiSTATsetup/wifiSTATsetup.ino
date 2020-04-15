
#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3);
     
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // esp's baud rate
 
 
  //sendData("AT+RST\r\n",2000,DEBUG); // reset module
 
  sendData("AT+CWMODE=1\r\n",2000,DEBUG); // set mode

  sendData("AT+CWLAP\r\n",10000,DEBUG); 
 
  sendData("AT+CWJAP=\"accesspoint\",\"1234\"\r\n",10000,DEBUG); // set access point

  sendData("AT+CIPMUX=0\r\n",5000,DEBUG);
  
  sendData("AT+CIPSTART=\"TCP\",\"192.168.4.1\",333\r\n",5000,DEBUG); // connect to api
 
  sendData("AT+CIPSEND=5\r\n",2000,DEBUG); // tell module request is 85 bytes
 
  sendData("hello\r\n",1000,DEBUG); // Send HTTP Request

  sendData("AT+CIPSEND=11\r\n",2000,DEBUG); // tell module request is 85 bytes
 
  sendData("raghavendra\r\n",1000,DEBUG); // Send HTTP Request
 
}
 
void loop()
{



}



String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
   
    esp8266.print(command); // send the read character to the esp8266
   
    long int time = millis();
 
     boolean wait = false;
   
    while( (time+timeout) > millis())
    {
     
      while(esp8266.available())
      {
       
        // read and save the next character.
        response += (char)esp8266.read();
       
      } 
     
    }
   
    if(debug)
    {
      Serial.print(response);
    }
   
    return response;
}
