#include <SoftwareSerial.h>
SoftwareSerial ESPserial(2, 3); // RX | TX
SoftwareSerial mySerial(5,6);
int count = 0;                                          // count = 0
char input[12];                                         // character array of size 12 
boolean flag = 0;  
void setup() 
{
    Serial.begin(9600);     // communication with the host computer
    //while (!Serial)   { ; }
    mySerial.begin(9600);
    // Start the software serial for communication with the ESP8266
    ESPserial.begin(9600);  
 
    Serial.println("");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("Ready");
    Serial.println(""); 
    ESPserial.println("AT+CWMODE=1\r");
}
 
void loop() 
{
   if ( ESPserial.available())  { Serial.write( ESPserial.read() ); }
   if ( Serial.available() )    {ESPserial.write( Serial.read() );  }
}
