int sensorPin=A0;
int sensorValue=0;
int led=9;
int buzzer=12;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue<100){
    Serial.print("Fire detected");
    Serial.println("LED ON");
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    delay(sensorValue);
  }
}
