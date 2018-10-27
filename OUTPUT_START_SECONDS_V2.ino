#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

byte ya[8] = {0b01111, 0b10001, 0b10001, 0b01111, 0b00101, 0b01001, 0b10001, 0b00000};
byte b[8] {0b11111, 0b10000, 0b10000, 0b11110, 0b10001, 0b10001, 0b11110, 0b00000};
byte yu[8] {0b10001, 0b10001, 0b10001, 0b11001, 0b10101, 0b10101, 0b11001, 0b00000};

void setup() {  
  lcd.init(); lcd.backlight(); lcd.createChar(1, ya); lcd.createChar(2, b); lcd.createChar(3, yu);
  lcd.setCursor(1,0); lcd.print("BPEM"); lcd.print(char(1));
  lcd.setCursor(9,0); lcd.print("PA"); lcd.print(char(2)); lcd.print("OT"); lcd.print(char(3));
}

void loop() {
int time=millis()/1000;
lcd.setCursor(4,1);
if (time/60/60<10) { lcd.print ("0"); }
lcd.print (time/60/60);
lcd.print (":");
if (time/60%60<10) { lcd.print ("0"); }
lcd.print ((time/60)%60);
lcd.print (":");
if (time%60<10) { lcd.print ("0"); }
lcd.print (time%60);
}
