int LDR = A0;
int ldrValue = 0;
int light_sensitivity = 500;
void setup(){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}
void loop(){
  ldrValue = analogRead(LDR);
  Serial.println(ldrValue);
  if(ldrValue < light_sensitivity){
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(11,LOW);
  }
//  delay(1000);
}
