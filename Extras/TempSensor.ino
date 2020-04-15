int analogoutput=A0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int sensevalue=analogRead(analogoutput);
    float milivolts=(sensevalue/1024.0)*500;
    float celsius=milivolts/10;
    Serial.print(celsius);
    Serial.print("degree Celsius\n");
    Serial.print((celsius * 9)/5+32);
    Serial.print("degree Fahrenheit\n");
    delay(5000);
}
