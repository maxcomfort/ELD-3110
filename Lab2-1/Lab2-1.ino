// Define the pins for the LEDs and the pushbutton
int switchPin = 8;
int redLED = 13;
int yellowLED = 12;
int greenLED = 11;

// Define a variable to store the button state
int buttonState = 0;

void setup() {
  // Set the LED pins as outputs and switchPin as an input 
  pinMode(switchPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Serial Monitor
  Serial.begin(9600);

}

void loop() {
   // Read the button state
  buttonState = digitalRead(switchPin);
  Serial.println(buttonState);
  // If the button is not pressed, run the LED sequence
  if (buttonState == LOW) {
    // Turn on the red LED and turn off the others
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    // Wait for one second
    delay(500);

    // Turn on the yellow LED and turn off the others
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    // Wait for one second
    delay(500);

    // Turn on the green LED and turn off the others
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    // Wait for one second
    delay(500);
  }
  else {
    delay (1000);
  }
}

