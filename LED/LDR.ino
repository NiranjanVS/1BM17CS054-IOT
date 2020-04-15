int ldr=A0;
int ldrValue = 0;
int light_sensitivity = 400; 
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  ldrValue = analogRead(ldr);
  Serial.println(ldrValue);
  delay(50);
  if(ldrValue<light_sensitivity){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  // put your main code here, to run repeatedly:
delay(1000);
}
