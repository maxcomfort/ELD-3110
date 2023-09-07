// Define the pins for the LED and the potentiometer
const int LED = 9; // use a PWM pin
const int POT = A0; // use an analog pin

// Define a variable to store the potentiometer value
int potValue = 0;

void setup() {
  // Set the LED pin as output
  pinMode(LED, OUTPUT);

  // Set the potentiometer pin as input
  pinMode(POT, INPUT);

  // Serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value
  potValue = analogRead(POT);

  // Output potValue to Serial Monitor
  Serial.println(potValue);
  // Map the potentiometer value to a range from 0 to 255
  potValue = map(potValue, 0, 1023, 0, 255);

  // Write the potentiometer value to the LED pin
  analogWrite(LED, potValue);

  // Wait for a short time
  delay(10);
}
