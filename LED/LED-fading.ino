int redpin =9;
int yellowpin=11;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int fadevalue=0;fadevalue<=25;fadevalue+=1){
analogWrite(redpin,fadevalue*10);
analogWrite(yellowpin,fadevalue/10);
delay(300);
}
for(int fadevalue=25;fadevalue>=0;fadevalue-=1){
  analogWrite(redpin,fadevalue/10);
  analogWrite(yellowpin,fadevalue*10);
  delay(300);}
}
