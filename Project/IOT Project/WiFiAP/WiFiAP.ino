
#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3);
SoftwareSerial rfid(5,6);
int count = 0;                                        
char input[12];                                        
boolean flag = 0;        
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // esp's baud rate
  rfid.begin(9600);
 
  sendData("AT+CWMODE=2\r\n",2000,DEBUG); // set mode
 
  sendData("AT+CWSAP=\"accesspoint\",\"1234\",3,0\r\n",2000,DEBUG); // set access point

  sendData("AT+CIPMUX=1\r\n",5000,DEBUG);
  
  sendData("AT+CIPSERVER=1\r\n",5000,DEBUG); // connect to api
 
}
 
void loop()
{
    receivewifi(1000);
    rfidread(1000);
}
 
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    esp8266.listen();
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
      Serial.println(response);
    }
   
    return response;
}
void receivewifi(const int timeout){
  String response = "";
  long int time = millis();
     esp8266.listen();
     boolean wait = false;
   
    while( (time+timeout) > millis())
    {
     
      while(esp8266.available())
      {
       
        // read and save the next character.
        response += (char)esp8266.read();
        wait=true;
      } 
     
    }
   
    if(wait)
    {
      Serial.print(response);
      Serial.print(" Cabin");
      Serial.println(" available");
    }
}
void rfidread(const int timeout){
  char input1[12];
  long int time = millis();
  rfid.listen();
  boolean wait = false;
   while( (time+timeout) > millis())
    {
    if(rfid.available())
   {  //Serial.println("calling rfidread");
      count = 0;
      while(rfid.available() && count < 12)         
      {
         input1[count] =rfid.read();
         count++;
         delay(5);
        // Serial.println(".");
         wait=true;
      }
   }}
    
    if(wait)
    {
      Serial.print(input1); 
      Serial.print(" class");
      Serial.println(" busy");
    }
}
         
