#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 8;
const int echoPin = 9;
const int ledYellow=10;
const int ledRed=11;

long duration;
int distance;
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledRed, OUTPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.println(distance);
if(distance<13)
{
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("     WELCOME   "); // Prints string "Distance" on the LCD
lcd.setCursor(0,1);
lcd.print("   IEEE-TUNNEL ");
}
else
{
  lcd.setCursor(0,0);
  lcd.print("   TATHVA 2k17  ");
  lcd.setCursor(0,1);
  lcd.print("  SAVE WILDLIFE ");
}

if(distance<13)
{
  digitalWrite(ledYellow,HIGH);
  digitalWrite(ledRed,LOW);
  delay(500);
}
else
{
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledRed,HIGH);
  delay(500);
}
}
