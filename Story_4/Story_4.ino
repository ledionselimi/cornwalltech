int rev_left = 12;
int fwd_left = 11;
int stop_left = 10;
int stop_right = 9;
int fwd_right = 7;
int rev_right = 8;

// Functions

void rover_forward(){

}


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

// Functions

void flash_LED(){
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