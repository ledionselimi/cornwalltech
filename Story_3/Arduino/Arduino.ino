// C++ code
//
int animationSpeed = 0;

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  animationSpeed = 5000;
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  animationSpeed = 1000;
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  animationSpeed = 2000;
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}