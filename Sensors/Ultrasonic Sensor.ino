const int trigpin=2;
const int echopin=3;
int readvalue;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,LOW);
delay(10);
digitalWrite(2,HIGH);
delay(10);
digitalWrite(2,LOW);
int duration = pulseIn(3,HIGH);
Serial.println(duration);
//float sec = duration/1000000;
//float dist = (sec*170);
//int cmdist = dist*100;
float cmdist = (duration/29)/2;
Serial.println(cmdist);
delay(1000);
}
