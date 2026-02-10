void setup() {
  // Initialize both digital pins as outputs
  pinMode(11, OUTPUT); // Red LED
  pinMode(12, OUTPUT); // Green LED
}

void loop() {
  // Turn Red LED on, Green LED off
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(1000); // Wait for 1 second

  // Turn Red LED off, Green LED on
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000); // Wait for 1 second
}