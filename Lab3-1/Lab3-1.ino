#include <IRremote.h>

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

int led1 = 11;
int led3 = 13;
int led2 = 12;

bool led1On = true;
bool led2On = true;
bool led3On = true;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    switch (results.value)
    {
      case 0xFF30CF:
        if (led1On) {
          digitalWrite(led1, LOW);
          led1On = false;
        }
        else {
          digitalWrite(led1, HIGH);
          led1On = true;
        }
        break;
      case 0xFF18E7:
        if (led2On) {
          digitalWrite(led2, LOW);
          led2On = false;
        }
        else {
          digitalWrite(led2, HIGH);
          led2On = true;
        }   
        break;
      case 0xFF7A85:
   if (led3On) {
        digitalWrite(led3, LOW);
        led3On = false;
        }
        else {
        digitalWrite(led3, HIGH);
        led3On = true;
        }   
        break;
    }
    irrecv.resume();
  }
}