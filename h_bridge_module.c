/*
    Project name : H-Bridge Module
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-h-bridge-module
*/

// H-Bridge Module Pin Configuration
const int motorPin1 = 8;  // Motor terminal 1 connected to digital pin 8
const int motorPin2 = 9;  // Motor terminal 2 connected to digital pin 9
const int enablePin = 10; // Enable pin connected to digital pin 10

void setup() {
  // Set motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Initialize Serial communication
  Serial.begin(9600);
  
  // Set motor to initially stop
  stopMotor();
}

void loop() {
  // Forward direction
  Serial.println("Moving Forward");
  moveForward();
  delay(2000); // Move forward for 2 seconds
  
  // Stop briefly
  stopMotor();
  delay(1000); // Stop for 1 second
  
  // Reverse direction
  Serial.println("Moving Backward");
  moveBackward();
  delay(2000); // Move backward for 2 seconds
  
  // Stop briefly
  stopMotor();
  delay(1000); // Stop for 1 second
}

void moveForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(enablePin, HIGH); // Enable motor movement
}

void moveBackward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(enablePin, HIGH); // Enable motor movement
}

void stopMotor() {
  digitalWrite(enablePin, LOW); // Disable motor movement
}
