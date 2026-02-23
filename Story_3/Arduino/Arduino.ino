// C++ code
//
int animationSpeed = 0;
int rev_left = 12; 
int fwd_left = 11; 
int stop_left = 10;   
int stop_right = 9;
int rev_right = 8; 
int fwd_right = 7;

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
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right, LOW);
  animationSpeed = 1000;
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(stop_left, LOW);
  digitalWrite(stop_right, LOW);
  animationSpeed = 2000;
  digitalWrite(rev_left, HIGH);
  digitalWrite(rev_right, HIGH);
  delay(animationSpeed); // Wait for animationSpeed millisecond(s)
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
}