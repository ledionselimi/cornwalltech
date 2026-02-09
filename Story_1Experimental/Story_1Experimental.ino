
// Define the LED pins
const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 11;
const int buttonPin = 2; // Push button connected to digital pin 2

// Define the Potentiometer pin
const int potPin = A0; 

// Variables to manage time using millis()
long greenDuration;
long yellowDuration;
long redDuration;
long startTime = 0;

// Variable to store the button state
int buttonState = 0;

void setup() {
  // Set the LED pins as OUTPUTs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  // Set the button pin as an INPUT
  pinMode(buttonPin, INPUT);
  
  // Set initial durations (milliseconds) - these will be adjusted by the pot
  greenDuration = 5000; 
  yellowDuration = 2000;
  redDuration = 5000;
  startTime = millis(); // Record the start time
}

void loop() {
  // Read the potentiometer and button values
  int potValue = analogRead(potPin); 
  // Map the 0-1023 pot value to a useful time range (e.g., 1 to 10 seconds)
  redDuration = map(potValue, 0, 1023, 1000, 10000); 
  greenDuration = map(potValue, 0, 1023, 1000, 10000);
  yellowDuration = greenDuration / 2;

  buttonState = digitalRead(buttonPin); // Read the button's state

  // Check if the button is pressed (HIGH signal)
  if (buttonState == HIGH) {
    // If pressed, immediately start the sequence to red
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH); // Yellow light on briefly
    delay(yellowDuration / 4); // Short delay for immediate yellow
    
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH); // Red light on for a set time (e.g., 5 seconds)
    delay(5000); // Pedestrian crossing time
    
    // After crossing time, return to normal sequence (green)
    startTime = millis(); // Reset the timer to continue the normal cycle
  } else {
    // --- Normal Traffic Light Sequence (using millis) ---
    // This logic checks if enough time has passed to change the lights
    if (millis() - startTime < greenDuration) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
    } else if (millis() - startTime < greenDuration + yellowDuration) {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
    } else if (millis() - startTime < greenDuration + yellowDuration + redDuration) {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
    } else {
      startTime = millis(); // Reset the cycle
    }
  }
}