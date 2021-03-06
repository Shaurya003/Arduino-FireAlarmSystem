#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); //rs,en,d4,d5,d6,d7
int flame=8,gas=10;
const int sounder=9;
void setup()
{ lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("FireAlarmSystem");
  delay(500);
  lcd.clear();
  pinMode(sounder, OUTPUT);
  pinMode(flame, INPUT_PULLUP);
  pinMode(gas, INPUT_PULLUP);
}
void loop()
{  int fire=(digitalRead(flame)== 1); 
   int gasleak=(digitalRead(gas)== 1);
   if(gasleak && fire)
   {
    lcd.print("FireAlert!");
    lcd.setCursor(0,1);
    lcd.print("GAS LEAK!");
    tone(sounder, 5000);
    delay(100);
    noTone(sounder);
    lcd.clear();
    }
    else if(fire)
    {
       lcd.print("FireAlert!");
       tone(sounder, 1000);
       delay(100);
       noTone(sounder);
       lcd.clear();
    }  
    else if(gasleak) 
    {
       lcd.print("GAS LEAK!");
       tone(sounder, 7000);
       delay(100);
       noTone(sounder);
       lcd.clear();
    }
       
}
