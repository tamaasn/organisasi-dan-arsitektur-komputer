#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 , 16 , 2);


#define TRIG_PIN 18
#define ECHO_PIN 19

unsigned long duration;
int distance;
char status[256];
int text_length;


void setup(){
  lcd.init();
  lcd.backlight();
  pinMode(TRIG_PIN , OUTPUT);
  pinMode(ECHO_PIN , INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG_PIN , LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN , HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN , LOW);

  duration = pulseIn(ECHO_PIN , HIGH);
  distance = duration / 29 / 2;
  if (duration == 0){
    snprintf(status , sizeof(status) , "Sensor error");
  }
  else{
    snprintf(status , sizeof(status) , "%d" , distance);
  }
  lcd.clear();
  lcd.setCursor(0 , 0);
  lcd.print(status);
  delay(1000);
}