int rev_left = 12;
int fwd_left = 11;

// Functions

void rover_forward(){

}


void setup()
{
  pinMode(rev_left, OUTPUT);
  pinMode(fwd_left, OUTPUT);
}

void loop()
{
  flash_LED(250);
}

// Functions

void flash_LED(int delaytime){
digitalWrite(rev_left, HIGH);
  delay(delaytime); // Wait for 1000 millisecond(s)
  digitalWrite(rev_left, LOW);
  delay(delaytime); // Wait for 1000 millisecond(s)
   digitalWrite(fwd_left, HIGH);
  delay(delaytime); // Wait for 1000 millisecond(s)
  digitalWrite(fwd_left, LOW);
  delay(delaytime); // Wait for 1000 millisecond(s)
}