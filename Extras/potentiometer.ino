const int analogPinIn = A0;
//const int analogPinOut = 9;
int sensor = 0;
int outputValue = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(analogPinIn);
  outputValue = map(sensor, 0, 1023, 0, 255);
  analogWrite(9, outputValue);
  Serial.print("Sensor = ");
  Serial.println(sensor);
  Serial.print("Output = ");
  Serial.println(outputValue);
  delay(200);
}
