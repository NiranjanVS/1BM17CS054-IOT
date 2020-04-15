int OutPut= 10;
int red_light_pin= 11;
int green_light_pin = 9;
int blue_light_pin = 6;
unsigned int frequency1 = 0;
unsigned int frequency2 = 0;
unsigned int frequency3 = 0;

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}


void setup()

{     Serial.begin(9600);
                pinMode(2, OUTPUT);
                pinMode(3, OUTPUT);
                pinMode(4, OUTPUT);
                pinMode(5, OUTPUT);
                pinMode(10, INPUT);
                digitalWrite(2,HIGH);
                digitalWrite(3,LOW);
                 pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

}
void loop()

{ RGB_color(frequency1,frequency2,frequency3);
//RGB_color(0,0,255); 
          Serial.println("R=");
                digitalWrite(4,LOW);
                digitalWrite(5,LOW);
                frequency1 = pulseIn(OutPut, LOW);
                Serial.println(frequency1);
                delay(500);
               Serial.println("B=");
                digitalWrite(4,LOW);
                digitalWrite(5,HIGH);
                frequency2 = pulseIn(OutPut, LOW);
                Serial.println(frequency2);
                delay(500);

               Serial.println("g=");
                digitalWrite(4,HIGH);
                digitalWrite(5,HIGH);// setting for GREEN color sensor
                frequency3 = pulseIn(OutPut, LOW);// reading frequency
                Serial.println(frequency3);
                delay(500);        

}    
