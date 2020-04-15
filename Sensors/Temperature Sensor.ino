int tempsensed;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempsensed=analogRead(A0);
  float millivolts=((tempsensed/1024.0)*5000);
  float celsius =millivolts/10;
  Serial.print(celsius);
  Serial.println("Degree Celsius: ");
  
  Serial.print(((celsius*9)/5)+32);
  Serial.println("Degree Fahrenheit: ");
  delay(1000);
}
