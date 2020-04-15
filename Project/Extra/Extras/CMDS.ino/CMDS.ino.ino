
#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3);
SoftwareSerial mySerial(4,5);
int count = 0; // count = 0
char input[12]; // character array of size 12
boolean flag = 0; // flag =0
     
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // esp's baud rate
  mySerial.begin(9600);
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

 // esp8266.end();
 
}
 
void loop()
{
  //mySerial.begin(9600);
  mySerial.listen();
  if(mySerial.available())
   {
     count = 0;
     while(mySerial.available() && count < 12) // Read 12 characters and store them in
    //input array
     {
       input[count] =mySerial.read();
       count++;
       delay(5);
     }
     Serial.println(input);// Print RFID tag number
//     esp8266.listen();
//     esp8266.print("AT+CIPSEND=12\r\n"); // tell module request is 85 bytes
// 
//     esp8266.print(input);
//     esp8266.print("\r\n");
       sendData("AT+CIPSEND=12\r\n",2000,DEBUG);
       sendData(input,1000,DEBUG);
   }

  // mySerial.end();

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
      Serial.print(response);
    }
   
    return response;
}
