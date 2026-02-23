int rev_left = 12; 
int fwd_left = 11; 
int stop_left = 10;   
int stop_right = 9;
int rev_right = 8; 
int fwd_right = 7;

void setup() {
  pinMode(rev_left, OUTPUT);
  pinMode(fwd_left, OUTPUT);
  pinMode(stop_left, OUTPUT);
  pinMode(stop_right, OUTPUT);
  pinMode(rev_right, OUTPUT); 
  pinMode(fwd_right, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  Story_7(); 
}

void Story_7() {
  fwdRover();
  delay(2000); 
  stopRover();

  for (int i = 0; i < 4; i++) {
    leftRover();
    fwdRover();   
    delay(500);   
    stopRover();
    delay(150);
  }
  for (int i = 0; i < 4; i++) {
    rightRover(); 
    fwdRover();   
    delay(500);   
    stopRover();
    delay(150);
  }
  stopRover();
  while(1); 
}

void fwdRover() {
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
}

void stopRover() {
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right, LOW);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, LOW);
  digitalWrite(stop_right, LOW);
}

void leftRover() {
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(850);
}

void rightRover() {
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, LOW);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(850);
}