int rev_left = 12; 
int fwd_left = 11; 
int stop_left = 10;   
int stop_right = 9;
int rev_right = 8; 
int fwd_right = 7;

#define TRIGGER_PIN  4  
#define ECHO_PIN     5  
#define MAX_DISTANCE 200 

void setup() {
  pinMode(rev_left, OUTPUT);
  pinMode(fwd_left, OUTPUT);
  pinMode(stop_left, OUTPUT);
  pinMode(stop_right, OUTPUT);
  pinMode(rev_right, OUTPUT); 
  pinMode(fwd_right, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
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

void checkEnvironment() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = (duration * 0.034) / 2;

  if (distance > 0 && distance < 12) {
    Serial.println("Obstacle");

    stopRover();
    delay(1000); 
  
    digitalWrite(rev_left, HIGH);
    digitalWrite(rev_right, HIGH);
    digitalWrite(fwd_left, LOW);
    digitalWrite(fwd_right, LOW);
    digitalWrite(stop_left, HIGH);
    digitalWrite(stop_right, HIGH);
    delay(1000); 
    stopRover();
    delay(200);

    leftRover(); 
    stopRover();
    
    Serial.println("Avoidance maneuvre completed.");
  }
}


void fwdRover() {
  checkEnvironment(); 
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
  checkEnvironment();
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right, HIGH);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(850);
}

void rightRover() {
  checkEnvironment();
  digitalWrite(fwd_left, HIGH);
  digitalWrite(fwd_right, LOW);
  digitalWrite(rev_left, LOW);
  digitalWrite(rev_right, LOW);
  digitalWrite(stop_left, HIGH);
  digitalWrite(stop_right, HIGH);
  delay(850);
}