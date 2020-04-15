
#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3);
SoftwareSerial rfid(5,6);
int count = 0;                                          // count = 0
char input[12];                                         // character array of size 12 
boolean flag = 0;        
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // esp's baud rate
  rfid.begin(9600);
 
  //sendData("AT+RST\r\n",2000,DEBUG); // reset module
 
  sendData("AT+CWMODE=2\r\n",2000,DEBUG); // set mode

  //sendData("AT+CWLAP\r\n",10000,DEBUG); 
 
  sendData("AT+CWSAP=\"accesspoint\",\"1234\",3,0\r\n",2000,DEBUG); // set access point

  sendData("AT+CIPMUX=1\r\n",5000,DEBUG);
  
  sendData("AT+CIPSERVER=1\r\n",5000,DEBUG); // connect to api
 
//  sendData("AT+CIPSEND=5\r\n",2000,DEBUG); // tell module request is 85 bytes
// 
//  sendData("hello\r\n",1000,DEBUG); // Send HTTP Request
//
//  sendData("AT+CIPSEND=11\r\n",2000,DEBUG); // tell module request is 85 bytes
// 
//  sendData("raghavendra\r\n",1000,DEBUG); // Send HTTP Request
 
}
 
void loop()
{
  //esp8266.listen();
  //if(esp8266.available())
 // {
  //  Serial.write(esp8266.read());
  //}
    
    receivewifi();
  
    
    rfidread();
   
}
 
/*
* Name: sendData
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the esp8266 (if there is a reponse)
*/
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
void receivewifi(){
  String response = "";
  long int time = millis();
     esp8266.listen();
     boolean wait = false;
   
    while( (time+1000) > millis())
    {
     
      while(esp8266.available())
      {
       
        // read and save the next character.
        response += (char)esp8266.read();
        wait=true;
        //Serial.println("calling wifi");
      } 
     
    }
   
    if(wait)
    {
      Serial.println(response);
      Serial.println("wifi reading done");
    }
}
void rfidread(){
  char input1[12];
  long int time = millis();
  rfid.listen();
  boolean wait = false;
   while( (time+1000) > millis())
    {
    if(rfid.available())
   {  //Serial.println("calling rfidread");
      count = 0;
      while(rfid.available() && count < 12)          // Read 12 characters and store them in input array
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
      Serial.println(input1);                             // Print RFID tag number 
      Serial.println("DONE rfid");
         }
}
         
