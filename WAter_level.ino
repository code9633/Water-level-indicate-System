
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>



#define trigpin 2
#define echopin 3
int green1 = A5;
int green2 = A4;
int yellow1 = A3;
int yellow2 = A2;
int red1 = A1;
int red2 = A0;
char auth[] = "YourAuthToken";

LiquidCrystal lcd(7, 6, 5, 4, 8, 9 );

float time = 0, distance = 0;

void setup()
{

  Serial.begin(9600);



  Serial.println("Waiting for connections...");

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("WATER LEVEL");
  lcd.setCursor(1, 1);
  lcd.print("CONTROL SYSTEM");
  delay(2000);

  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  delay(1000);
}

void loop()
{

  int duration, distance, percentage;
  digitalWrite(trigpin, HIGH);

  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);


  duration = pulseIn(echopin, HIGH);

  distance = time * 0.10 / 2;
  percentage = 100 - (distance / 3);
  Serial.println(" Distance cm:");
  Serial.println(percentage);



  lcd.clear();
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  time = pulseIn(echopin, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("LEVEL:");
  lcd.setCursor(0, 1);
  lcd.print("CURRENT STATUS:");
  delay(10);

  if (  (distance > 0) && (distance <= 40)   )
  {
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    lcd.setCursor(7, 0);
    lcd.print("LOW");
    lcd.setCursor(7, 1);
    lcd.print("Normal");
    delay(1000);
  } else if (  (distance > 40) && (distance <= 50)  )
  {

    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    lcd.setCursor(7, 0);
    lcd.print("LOW");
    lcd.setCursor(7, 1);
    lcd.print("NORMAL");
    delay(1000);
  } else

    if (  (distance > 50) && (distance <= 60)  )
    {

      digitalWrite(green1, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(yellow1, HIGH);
      digitalWrite(yellow2, LOW);
      digitalWrite(red1, LOW);
      digitalWrite(red2, LOW);
      lcd.setCursor(7, 0);
      lcd.print("LOW-MEDIUM");
      lcd.setCursor(7, 1);
      lcd.print("LOW-RISK");
      delay(1000);
    } else


      if (  (distance > 60) && (distance <= 70)  )
      {

        digitalWrite(green1, HIGH);
        digitalWrite(green2, HIGH);
        digitalWrite(yellow1, LOW);
        digitalWrite(yellow2, LOW );
        digitalWrite(red1, LOW);
        digitalWrite(red2, LOW);
        lcd.setCursor(7, 0);
        lcd.print("HIGH-MEDIUM");
        lcd.setCursor(7, 1);
        lcd.print("HIGH-RISK");
        delay(1000);
      }
      else if (distance > 71)
      {

        digitalWrite(green1, HIGH);
        digitalWrite(green2, LOW);
        digitalWrite(yellow1, LOW);
        digitalWrite(yellow2, LOW );
        digitalWrite(red1, LOW);
        digitalWrite(red2, LOW);
        lcd.setCursor(7, 0);
        lcd.print("HIGH");
        lcd.setCursor(7, 1);
        lcd.print("DANGEROUS");
        delay(1000);
      }



}
