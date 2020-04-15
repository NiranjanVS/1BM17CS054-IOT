int ledPin = 13;
int inPin = 2;
int value = 0;
void setup() {
  pinMode(inPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(inPin);
  if(value ==HIGH){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  

}
