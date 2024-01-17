#include <LiquidCrystal.h>

const int geel = A0;
const int groen = A1;
const int blauw = A2;
const int paars = A3;
const int beginknop = 10;
const int knopgeel = 9;
const int knopgroen = 8;
const int knopbluaw = 7;
const int knoppaars = 6;
int level = 1;
int lijst[20];
int knoplijst[20];
int list = 0;
int knoop = 0;
int lijstgrote = level;  
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int begin = 0;
int pos = 0;
int knoppen = 0;
int knop = 0;

bool vergelijk(int a1[], int a2[], int lengte) {
  for (int i = 0; i < level; i++){
    if (a1[i] == a2[i]){
    }
    else{
      return false;
    }
  } 
  return true;
}


void setup() {
  lcd.begin(16, 2);
  pinMode(geel, OUTPUT);
  pinMode(groen, OUTPUT);
  pinMode(blauw, OUTPUT);
  pinMode(paars, OUTPUT);
  pinMode(knopgeel, INPUT);
  pinMode(knopgroen, INPUT);
  pinMode(knopbluaw, INPUT);
  pinMode(knoppaars, INPUT);
  pinMode(beginknop, INPUT);
  Serial.begin(9600);
}

void loop() {
  begin = digitalRead(beginknop);
  if (begin == HIGH) {
    lcd.print("start");

    for (int i = 0; i < level; i++) {
      delay(500);
      int light = random(1, 5);
      lijst[i] = light;
      list = list + light;

      switch (light) {
        case 1:
          digitalWrite(geel, HIGH);
          delay(500);
          digitalWrite(geel, LOW);
          break;
        case 2:
          digitalWrite(groen, HIGH);
          delay(500);
          digitalWrite(groen, LOW);
          break;
        case 3:
          digitalWrite(blauw, HIGH);
          delay(500);
          digitalWrite(blauw, LOW);
          break;
        case 4:
          digitalWrite(paars, HIGH);
          delay(500);
          digitalWrite(paars, LOW);
          break;
        default:
        break;
      }
    }
    lcd.clear();

    Serial.print("lijst: ");

    for (int i = 0; i < level; i++) {
      Serial.print(lijst[i]);
      Serial.print(" ");
    }
    Serial.println(); 
    knoppen = 1;

  }
  if (knoppen == 1){
    int pos = 0;

    while (pos < level){
      int knop1 = digitalRead(knopgeel);
      int knop2 = digitalRead(knopgroen);
      int knop3 = digitalRead(knopbluaw);
      int knop4 = digitalRead(knoppaars);

      if (knop1 == HIGH) {
        knop = 1;
        knoplijst[pos] = knop;
        pos++;
        knoop = knoop + 1;
        digitalWrite(geel, HIGH);
        delay(500);
        digitalWrite(geel, LOW);
        delay(500);
      } 
      else if (knop2 == HIGH) {
        knop = 2;
        knoplijst[pos] = knop;
        pos++;
        knoop = knoop + 2;
        digitalWrite(groen, HIGH);
        delay(500);
        digitalWrite(groen, LOW);
        delay(500);
      }
      else if (knop3 == HIGH) {
        knop = 3; 
        knoplijst[pos] = knop;
        pos++;
        knoop = knoop + 3;
        digitalWrite(blauw, HIGH);
        delay(500);
        digitalWrite(blauw, LOW);
        delay(500);
      }
      else if (knop4 == HIGH) {
        knop = 4; 
        knoplijst[pos] = knop;
        pos++;
        knoop = knoop + 4;
        digitalWrite(paars, HIGH);
        delay(500);
        digitalWrite(paars, LOW);
        delay(500);
      }

    }

    Serial.print("knoplijst: ");
    for (int i = 0; i < level; i++) {
      Serial.print(knoplijst[i]);
      Serial.print(" ");
    } 

    

    if (vergelijk(knoplijst, lijst, level) == true){
      lcd.print("correct");
      delay(1500);
      level++;
    }
    else{
      lcd.print("incorrect");
      delay(5000);
      level = 1;
    }

    lcd.clear();
    if (level > 20){
      lcd.print("je hebt gewonnen!!!");
      for (int i = 0; i < 100; i++) {
      digitalWrite(blauw, HIGH);
      delay(100);
      digitalWrite(groen, HIGH);
      delay(100);
      digitalWrite(blauw, LOW);
      digitalWrite(geel, HIGH);
      delay(100);
      digitalWrite(geel, LOW);
      digitalWrite(groen, LOW);
      digitalWrite(paars, HIGH);
      delay(100);
      digitalWrite(paars, LOW);
      }
      delay(5000);
      level = 1;
    }
  }
  pos = 0;
  list = 0;
  knoop = 0;
  knoppen = 0;
  lcd.clear();
}
