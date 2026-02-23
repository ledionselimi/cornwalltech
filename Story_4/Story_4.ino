int rev_left = 12;
int fwd_left = 11;
int stop_left = 10;
int stop_right = 9;
int fwd_right = 7;
int rev_right = 8;

void setup()
{
pinMode(rev_left, OUTPUT);
pinMode(fwd_left, OUTPUT);
pinMode(stop_left, OUTPUT);
pinMode(stop_right, OUTPUT);
pinMode(fwd_right, OUTPUT);
pinMode(rev_right, OUTPUT);
}

void loop()
{
  flash_LED();
}

void flash_LED(){
forward();
delay(5000); // Wait for 5000 millisecond(s)
stop();
delay(1000); // Wait for 1000 millisecond(s)
reverse();
delay(2000); // Wait for 2000 millisecond(s)    
}

// Functions

void forward() {
digitalWrite(fwd_left, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
}

void stop() {
digitalWrite(fwd_left, LOW);
digitalWrite(fwd_right,LOW);
digitalWrite(rev_right, LOW);
digitalWrite(rev_left, LOW);
digitalWrite(stop_left, HIGH);
digitalWrite(stop_right, HIGH);
}

void reverse() {
digitalWrite(fwd_left, LOW);
digitalWrite(fwd_right,LOW);
digitalWrite(rev_right, HIGH);
digitalWrite(rev_left, HIGH);
digitalWrite(stop_left, HIGH);
digitalWrite(stop_right, HIGH);
}