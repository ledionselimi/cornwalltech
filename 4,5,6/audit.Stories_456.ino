int rev_left = 12;
int fwd_left = 11;
int stop_left = 10;   
int stop_right = 9;  
int rev_right = 8;
int fwd_right = 7;

const int RIGHT_FEEDBACK = 2; 
const int LEFT_FEEDBACK = 3;
volatile int leftcounter = 0; 
volatile int rightcounter = 0; 
const int TARGET_COUNT = 870;

void setup(){
  pinMode(rev_left, OUTPUT);
  pinMode(fwd_left, OUTPUT);
  pinMode(stop_left, OUTPUT);
  pinMode(stop_right, OUTPUT);
  pinMode(rev_right, OUTPUT);
  pinMode(fwd_right, OUTPUT);

  Serial.begin(115200);
  
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);
  
  digitalWrite(stop_left, HIGH);  
  digitalWrite(stop_right, HIGH);
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, HIGH);
}

void loop() {
  Serial.print("Left Counter: ");
  Serial.println(leftcounter);
  if (leftcounter >= TARGET_COUNT) {
    digitalWrite(stop_left, LOW);  
    digitalWrite(stop_right, LOW);
    digitalWrite(fwd_left, LOW);
    digitalWrite(fwd_right, LOW);
    Serial.println("2 Metres Reached. Program Terminated.");
    delay(100); 
    exit(0); 
  }
}

void LeftMotorISR() {
  leftcounter++;
}

void RightMotorISR() {
  rightcounter++;
}

void Story_4(){
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, HIGH);
  delay(5000);
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right,LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(1000);
  digitalWrite(stop_left, LOW);
  digitalWrite(stop_right, LOW);
  digitalWrite(rev_left, HIGH);
  digitalWrite(rev_right, HIGH);
  delay(2000);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);           
}

void Story_5(){
  moveRover(255, 255); 
  delay(2000);
  moveRover(80, 255); 
  delay(2000);
  moveRover(255, 80); 
  delay(2000);
  moveRover(80, 255); 
  delay(2000);
  moveRover(255, 80); 
  delay(2000);
  moveRover(0, 0);
  while(true);
}

void moveRover(int leftSpeed, int rightSpeed){
  digitalWrite(fwd_left, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_right, LOW);

  analogWrite(stop_left, leftSpeed);
  analogWrite(stop_right, rightSpeed);
}