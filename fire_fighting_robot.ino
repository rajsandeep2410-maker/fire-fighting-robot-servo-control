#include <Servo.h>

// IR Sensors
int leftSensor = 8;
int centerSensor = 7;
int rightSensor = 6;

// Motor 1 (Left side)
int motor1pin1 = 2;
int motor1pin2 = 3;

// Motor 2 (Right side)
int motor2pin1 = 4;
int motor2pin2 = 5;

// Enable pins
int ENA = 9;
int ENB = 10;

// Pump (Relay)
int pumpPin = 11;

// Servo
Servo nozzle;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(pumpPin, OUTPUT);

  nozzle.attach(12);

  // Speed
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void loop() {
  int left = digitalRead(leftSensor);
  int center = digitalRead(centerSensor);
  int right = digitalRead(rightSensor);

  if (left == LOW) {
    // Turn LEFT
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    nozzle.write(150);
    digitalWrite(11, HIGH);
  }

  else if (right == LOW) {
    // Turn RIGHT
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    nozzle.write(30);
    digitalWrite(11, HIGH);
  }

  else if (center == LOW) {
    // FORWARD
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    nozzle.write(90);
    digitalWrite(11, HIGH);
  }

  else {
    // STOP
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    digitalWrite(11, LOW);
  }
}
