
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
 
  sendData("AT+CWMODE=2\r\n",2000,DEBUG);
 
  sendData("AT+CWSAP=\"accesspoint\",\"1234\",3,0\r\n",2000,DEBUG);

  sendData("AT+CIPMUX=1\r\n",2000,DEBUG);
  
  sendData("AT+CIPSERVER=1\r\n",2000,DEBUG); // connect to api 
}
 
void loop()
{
  esp8266.listen();
  receivewifi();  

  delay(1000);
  
  rfid.listen();
  rfidread();

  delay(1000);
   
}
 

String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    esp8266.listen();
    esp8266.print(command);
    long int time = millis();
    boolean wait = false;
      while( (time+timeout) >= millis())
      {
          while(esp8266.available())
          {
       
            response += (char)esp8266.read();
       
          } 
     
      }
   
      if(debug)
      {
        Serial.println(response);
      }
    return response;
}


void receivewifi(){
  String response = "";
  bool read1=false;
  long int time = millis();
     esp8266.listen();
     boolean wait = false;
   
    while( (time+2000> millis()))
    {
     
      while(esp8266.available())
      {
        response += (char)esp8266.read();
        read1=true;
      } 
     
    }
   
    if(read1)
    {
      Serial.println(response);
    }
    
}



void rfidread(){
    char input1[12];
    bool read1=false;
    long int time = millis();
    rfid.listen();
    boolean wait = false;
   
    while( (time+2000) > millis())
    {
      if(rfid.available())
      {
      count = 0;
        while(rfid.available() && count < 12) 
        {
            input1[count] =rfid.read();
            count++;
            delay(5);
        }
        read1=true;
      }
    }
    if(read1)
    {
      Serial.print(input1);  
    }
}
         
