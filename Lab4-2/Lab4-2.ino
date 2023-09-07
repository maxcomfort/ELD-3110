int photoresistorPin = A0; // select the input pin for the photoresistor
int photoresistorValue = 0; // variable to store the value coming from the photoresistor

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  photoresistorValue = map(analogRead(photoresistorPin), 0, 1023, 0, 255); // read the value from the photoresistor
  Serial.println(photoresistorValue); // send the value to the serial port
  delay(100); // wait for 100 milliseconds before reading again
}
