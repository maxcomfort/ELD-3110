#include <DS3231.h>
#include <Wire.h>

DS3231 myRTC;

const int buttonPin = 2; // the pin number of the button
volatile int state = LOW; // the current state of the button
volatile int lastState = LOW; // the previous state of the button
bool century = false;
bool h12Flag;
bool pmFlag;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // start the I2C interface
  pinMode(buttonPin, INPUT_PULLUP); // set the button pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING); // attach interrupt to the button pin
}

void loop() {
  for (int i = 5; i <= 50; i += 5) { // loop through values from 5 to 50 in increments of 5
    if (state != lastState) { // check if the button state has changed
        Serial.print(myRTC.getYear(), DEC);
        Serial.print("-");
        Serial.print(myRTC.getMonth(century), DEC);
        Serial.print("-");
        Serial.print(myRTC.getDate(), DEC);
        Serial.print(" ");
        Serial.print(myRTC.getHour(h12Flag, pmFlag), DEC); //24-hr
        Serial.print(":");
        Serial.print(myRTC.getMinute(), DEC);
        Serial.print(":");
        Serial.println(myRTC.getSecond(), DEC); // print the new state to serial monitor  
        lastState = state; // update the previous state
      }
    Serial.println(i); // print the value to serial monitor
    delay(5000); // wait for 5 seconds\}
    
  }
}

void buttonPressed() {
  state = !state; // toggle the state of the button
}

