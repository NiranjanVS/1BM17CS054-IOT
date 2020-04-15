#include <LiquidCrystal.h>

uint8_t readPIR = 0;
uint8_t nomotionflag = 0;
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);  

void setup() {
  lcd.begin(16,2);         
  pinMode(9, INPUT);      
  digitalWrite(9, HIGH);  
  Serial.begin(9600);
}

void loop() {
  readPIR = digitalRead(9);   
  
  if (readPIR == 1){          
    nomotionflag = 0;         
    lcd.home();
    lcd.print("Motion Detected");
    Serial.print("Motion Detected");
    delay(500);
  }

  else{                         
    if (nomotionflag == 0){       
      lcd.clear();
      lcd.print("No motion");
      Serial.print("No motion");
      nomotionflag = 1;
    }
    
  }
  
}
