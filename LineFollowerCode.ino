
const int ENA = 10; 
const int IN1 = 6;  
const int IN2 = 7;  
#define s 100 
#define t 130


const int ENB = 11; 
const int IN3 = 8;  
const int IN4 = 9;  


const int IRSensorLeft = 4;   
const int IRSensorRight = 3;  

void setup() {
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  
  pinMode(IRSensorLeft, INPUT);
  pinMode(IRSensorRight, INPUT);

  
  Serial.begin(9600);
}

void loop() {
  bool leftSensor = digitalRead(IRSensorLeft);
  bool rightSensor = digitalRead(IRSensorRight);
  
  
  Serial.print("Left Sensor: ");
  Serial.print(leftSensor);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensor);

  
  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  }
  
  else if (leftSensor == LOW && rightSensor == HIGH) {
    turnRight();
  }
  
  else if (leftSensor == HIGH && rightSensor == LOW) {
    turnLeft();
  }
  
  else {
    stopMotors();
  }

  delay(100); 
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, s); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, s); 
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, t); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, t); 
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, t); 

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, t); 
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); 

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); 
}
