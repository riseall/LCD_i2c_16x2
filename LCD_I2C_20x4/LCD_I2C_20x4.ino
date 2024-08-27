#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;
int outputValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  analogWrite(ledPin, outputValue);
  lcd.setCursor(0,0);
  lcd.print("sensor = ");
  lcd.print(sensorValue);
  lcd.setCursor(0,1);

  lcd.print("output = ");
  lcd.print(outputValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
