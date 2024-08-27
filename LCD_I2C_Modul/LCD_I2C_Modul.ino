#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int i;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
   for(int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  //instruksi cursor
  lcd.setCursor(0, 0);

  //karakter
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Rizal Nugroho");
  delay(8000);

  //membersihkan layar LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("D4 TEKNOLOGI REKAYASA KOMPUTER");
  lcd.setCursor(0, 1);
  lcd.print("POLINES");
  for (i = 0; i < 16; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }

  //membersihkan layar LCD
  lcd.clear();
}

void loop() {
  if(Serial.available())
  {
    delay(100);

    //read karakter
    while(Serial.available() > 0 )
    {
      lcd.print("Ri");
      lcd.write(Serial.read());
    }
  }
}
