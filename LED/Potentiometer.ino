const int analogpin=0;
const int analogpinout=9;
int sensorvalue=0;
int outputvalue=0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvalue=analogRead(analogpin);
  outputvalue=map(sensorvalue,0,1023,0,255);
  analogWrite(analogpinout, outputvalue);
  Serial.print("sensor=");
Serial.println(sensorvalue);
Serial.print("output= ");
Serial.println(outputvalue);
delay(2000);
}
