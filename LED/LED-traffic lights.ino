int redpin=13;
int greenpin=12;
int yellowpin=11;
void setup() {
  // put your setup code here, to run once:
pinMode(redpin,OUTPUT);
pinMode(greenpin,OUTPUT);
pinMode(yellowpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(yellowpin,LOW);
digitalWrite(greenpin,LOW);
digitalWrite(redpin,HIGH);
delay(1000);
digitalWrite(redpin,LOW);
digitalWrite(greenpin,HIGH);
delay(500);
digitalWrite(greenpin,LOW);
digitalWrite(yellowpin,HIGH);
delay(1000);
}
