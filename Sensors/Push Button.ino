int btnread=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnread=digitalRead(2);
  if(btnread==HIGH){
    digitalWrite(13,HIGH);
    
  }
  else{
    digitalWrite(13,LOW);
  }
}
