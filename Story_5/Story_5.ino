int rev_left = 12;
int fwd_left = 11;
int stop_left = 10;
int stop_right = 9;
int fwd_right = 7;
int rev_right = 8;

void loop()
{
  Story_4();
  Story_5();
}

// Functions

void setup()
{
pinMode(rev_left, OUTPUT);
pinMode(fwd_left, OUTPUT);
pinMode(stop_left, OUTPUT);
pinMode(stop_right, OUTPUT);
pinMode(fwd_right, OUTPUT);
pinMode(rev_right, OUTPUT);
}

// Functions

void Story_4(){
digitalWrite(fwd_left, HIGH);
digitalWrite(fwd_right, HIGH);
delay(5000); // Wait for 5000 millisecond(s)
digitalWrite(fwd_left, LOW);
digitalWrite(fwd_right,LOW);
digitalWrite(stop_left, HIGH);
digitalWrite(stop_right, HIGH);
delay(1000); // Wait for 1000 millisecond(s)
digitalWrite(stop_left, LOW);
digitalWrite(stop_right, LOW);
digitalWrite(rev_left, HIGH);
digitalWrite(rev_right, HIGH);
delay(2000); // Wait for 2000 millisecond(s)
digitalWrite(rev_left, LOW);
digitalWrite(rev_right, LOW);           
}

// Functions

void Story_5(){
  moveRover(255, 255); 
  delay(2000); // Go for 2000 millisecond(s)
  moveRover(80, 255); 
  delay(2000); // Go for 2000 millisecond(s)
  moveRover(255, 80); 
  delay(2000); // Go for 2000 millisecond(s)
  moveRover(80, 255); 
  delay(2000); // Go for 2000 millisecond(s)
  moveRover(255, 80); 
  delay(2000); // Go for 2000 millisecond(s)
  moveRover(0, 0);
  while(true);
}

void moveRover(int leftSpeed, int rightSpeed) {
  digitalWrite(fwd_left, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_right, LOW);

  analogWrite(stop_left, leftSpeed);
  analogWrite(stop_right, rightSpeed);
}
