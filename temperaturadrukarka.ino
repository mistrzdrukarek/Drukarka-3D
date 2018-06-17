#include <LiquidCrystal.h>

#define TEMP0 13
#define a -7.81086316639610e-07
#define b 0.00135944941813236
#define c -0.865762638670255
#define d 292.399926740249
#define HEATER 10
#define FAN 44
//#define FAN2 9

LiquidCrystal lcd(16, 17, 23, 25, 27, 29);
int x;
double temp, e, u, i = 0,tempz;



void setup() {
  pinMode(HEATER, OUTPUT);
  digitalWrite(HEATER, LOW);
  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, HIGH);
  //pinMode(FAN2, OUTPUT);
  Serial.begin(57600);
  lcd.begin(20, 4);
  lcd.print("");
}

void loop() {
  x = analogRead(TEMP0);
  Serial.println(x);
  temp = a * (double)pow(x, 3) + b * (double)pow(x, 2) + c * (double)x + d;
  lcd.setCursor(0, 0);
  lcd.print(temp);
  tempz=100;
  e = tempz - temp; //blad
  i = i + (e * 0.01); //calkowanie (pole pow. = blad * opoznienie(10 ms))
  u = 255 * (e / (tempz-30)) + (i /10); //sterowanie
  if (temp < tempz)
  {
    analogWrite(HEATER, u > 255 ? 255 : floor(u)); //if(u>255){255}else{floor(u)}
    lcd.setCursor(0, 1);
    //lcd.print("Grzalka wlaczona");
    lcd.print(e);
    lcd.setCursor(0, 2);
    lcd.print(u);
    lcd.setCursor(0, 3);
    lcd.print(i);
  }
  else
  {
    digitalWrite(HEATER, LOW);
    //lcd.setCursor(0, 2);
    //lcd.print("Grzalka wylaczona");
    lcd.setCursor(0, 1);
    lcd.print(e);
    lcd.setCursor(0, 2);
    lcd.print(u);
    lcd.setCursor(0, 3);
    lcd.print(i);
  }
  delay(10);
}
