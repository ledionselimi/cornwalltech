int rev_left = 12; 
int fwd_left = 11; 
int stop_left = 10;   
int stop_right = 9;
int rev_right = 8; 
int fwd_right = 7;

#define TRIGGER_PIN  4  
#define ECHO_PIN     5  
#define MAX_DISTANCE 200 
const int TRIGGER_DOWN = 13;
const int ECHO_DOWN = 17;

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
  checkEnvironment();
  fwdRover(); 
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
  Serial.println("Drop Detected! Emergency Stop.");
    
  stopRover();
  delay(500);
  revRover(); 
  delay(500);
  stopRover();
  while(1); 
  Serial.println("Emergency stop.");
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

void revRover() {
  digitalWrite(fwd_left, LOW);
  digitalWrite(fwd_right, LOW);
  digitalWrite(rev_left, HIGH);
  digitalWrite(rev_right, HIGH);
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

