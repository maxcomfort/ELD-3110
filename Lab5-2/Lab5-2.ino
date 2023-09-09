#include <HCSR04.h>

HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int distance = hc.dist();
    if (distance > 100 || distance <= 2) {
        Serial.println("out of range");
    } else {
        Serial.println(distance); // return current distance in serial
    }
    delay(60);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
