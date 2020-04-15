int CalibrationTime=30;
long unsigned int lowIn;
long unsigned int pause=5000;
boolean locklow = true;
boolean takelowTime;
int pirPin=4;
int ledPin=13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pirPin,INPUT);
pinMode(ledPin,OUTPUT);
digitalWrite(pirPin,LOW);
Serial.print("CALIBERATING SENSOR");
for(int i = 0; i<CalibrationTime;i++)
{
  Serial.print('.');
  delay(1000);
}
Serial.println("DONE");
Serial.println("sensor Active");
delay(10);
}


void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(pirPin)==HIGH);
{
  digitalWrite(ledPin,HIGH);
  if(locklow){
    locklow=false;
    Serial.println("---");
    Serial.println("Motion detected at");
    Serial.println((millis()/1000));
    Serial.println("Sec.");
    delay(50);
  }
takelowTime = true;
}
if(digitalRead(pirPin)==LOW){
  digitalWrite(ledPin,LOW);
  if (takelowTime){
    lowIn=millis();
    takelowTime=false;
  }
if(!locklow && millis() - lowIn>pause){
  locklow=true;
  Serial.print("MOTION ENDED AT");
  Serial.print((millis() - pause)/1000);
  Serial.println("sec");
  delay(50);
}
}
}
