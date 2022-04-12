#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);



/*test - gunwoo*/
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("JongWon");
  lcd.setCursor(0,1);
  lcd.print("CDS:");
  lcd.setCursor(9,1);
  lcd.print("LED:");

  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  int val = analogRead(A0);  

  lcd.setCursor(4,1);
  lcd.print("    ");
  lcd.setCursor(4,1);
  lcd.print(val);
  
  String led;
  if(val>100){
    digitalWrite(13,0);
    led="OFF";
  }
  else{
    digitalWrite(13,1);
    led="ON";
  }
  lcd.setCursor(13,1);
  lcd.print("   ");
  lcd.setCursor(13,1);
  lcd.print(led);
  delay(500);
}
