#include <Servo.h>

int potPin = A0;
int servoPin = 9;

Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(servoPin);
}

void loop()
{
  int val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  Serial.print("Potentiometer output: ");
  Serial.println(val);
  delay(15);
}