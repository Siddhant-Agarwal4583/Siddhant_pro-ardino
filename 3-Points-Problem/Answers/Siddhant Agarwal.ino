#include <LiquidCrystal.h>

const int trigPin=6;
const int echoPin=7;
const int buzzer=8;
int count =0;

long duration;
int distance;

LiquidCrystal lcd(12,11,5,4,3,2);
  void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}
void loop(){
  lcd.clear();
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  delay(500);
  if(distance<25){
    tone(buzzer,2000);
    count++;
  }
  else 
    noTone(buzzer);

lcd.clear();
lcd.print("Distance");
lcd.print(distance);
lcd.print("cm");
lcd.setCursor(0,1);
lcd.print("No.of Person:");
lcd.print(count);
delay(1000);
Serial.print("Distance");
Serial.println(distance);
Serial.print("cm");
delay(1000);
}