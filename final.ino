#include<LiquidCrystal.h>
int pin1 = 6;
int pin2 = 7;
int sensorOne = 0;
int sensorTwo = 0;
int count = 0;
int timeIn =0;
int timeOut =0;
int sens1=0;
int sens2=0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
dp(count);
}

void loop() {
  sens1 = digitalRead(pin1);
  sens2 = digitalRead(pin2);
  if(sens1 == 1 && sens2 == 1){
    dp(count);
    delay(100);
    }else if(sens1 == 0){
      int timeIn = millis();
      while(sens1 == 0 && sens2 == 1){
        int timeOut = millis();
        if(timeOut-timeIn>1000){alert();}
        sens1 = digitalRead(pin1);
        sens2 = digitalRead(pin2);
        if(sens2 == 0){
          int timeIn1 = millis();
          while(sens2 == 0 && sens1 == 0){
            int timeOut1 = millis();
            if(timeOut1-timeIn1>1000){alert();}
            sens1 = digitalRead(pin1);
            sens2 = digitalRead(pin2);
            if(sens1 == 1){
              int timeIn2 = millis();
              while(sens1 == 1 && sens2 == 0){
                int timeOut2 = millis();
                if(timeOut2-timeIn2>1000){alert();}
                sens1 = digitalRead(pin1);
                sens2 = digitalRead(pin2);
                if(sens2 == 1){
                  if(count<0){count = 0;}
                  count = count+1;
                  dp(count);
                  }
                }
              }
            }
          }
        }
      }else if(sens2 == 0){
        int timeIn = millis();
        while(sens2 == 0 && sens1 == 1){
          int timeOut = millis();
          if(timeOut-timeIn > 1000){alert();}
          sens1 = digitalRead(pin1);
          sens2 = digitalRead(pin2);
          if(sens1 == 0){
            int timeIn1 = millis();
            while(sens1 == 0 && sens2 == 0){
              int timeOut1 = millis();
              if(timeOut1-timeIn1>1000){alert();}
                sens1 = digitalRead(pin1);
                sens2 = digitalRead(pin2);
                if(sens2 == 1){
                  int timeIn2 = millis();
                  while(sens1 ==0 && sens2 == 1){
                    int timeOut2 = millis();
                    if(timeOut2-timeIn2>1000){alert();}
                    sens1 = digitalRead(pin1);
                    sens2 = digitalRead(pin2);
                    if(sens1 == 1){
                      count = count -1;
                      dp(count);
                      }
                    }
                  }
              }
            }
          }
        }
}

void dp(int count){
  if(count<0){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     Alert!     ");
  lcd.setCursor(0,1);
  lcd.print("Don't Fool me!!!");
  lcd.print(count);
    }else{
       lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Total Students ");
  lcd.setCursor(0,1);
  if(count<10){
     lcd.print("Total Count =  ");
    lcd.print(count);
    }else if(count< 100){
       lcd.print("Total Count = ");
  lcd.print(count);
      }else if(count<1000){
         lcd.print("Total Count =");
  lcd.print(count);
        }
      }
}
void alert() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     Alert!     ");
  lcd.setCursor(0,1);
  lcd.print("Please Move !!!!");
  lcd.print(count);
  delay(10);
}
