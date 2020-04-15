
int sensorPin = A0;
int sensorValue = 0;
int led = 13;
int buzzer = 12;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  //digitalWrite(buzzer,HIGH);
      //digitalWrite(led,HIGH);
  if(sensorValue < 100){
    Serial.println("Fire Detector...");
    Serial.print("LED ON");
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
    digitalWrite(led,LOW);
    //digitalWrite(buzzer,LOW);
    delay(sensorValue);

}
