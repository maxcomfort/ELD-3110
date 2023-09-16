#include <HCSR04.h>
#include <LiquidCrystal.h>

HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)
const int rs = 12, en = 11, d4 = 10, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    Serial.begin(9600);
     // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
}

void loop()
{
    int distance = hc.dist();
    if (distance > 100 || distance <= 2) {
        lcd.clear();
        lcd.print("Out of Range!");
    } else {
        lcd.clear();
        lcd.print("Distance = ");
        lcd.print(distance); // return current distance
        lcd.print( " cm");
    }
    delay(60);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
