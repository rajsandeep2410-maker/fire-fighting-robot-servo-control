#include <Servo.h>

int leftSensor = 8;
int centerSensor = 7;
int rightSensor = 6;

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

int ENA = 9;
int ENB = 10;

int pumpPin = 11;

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

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void loop() {
  int left = digitalRead(leftSensor);
  int center = digitalRead(centerSensor);
  int right = digitalRead(rightSensor);

  if (left == LOW) {
    // Turn LEFT
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    nozzle.write(150);
    digitalWrite(pumpPin, HIGH);
  }

  else if (right == LOW) {
    // Turn RIGHT
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    nozzle.write(30);
    digitalWrite(pumpPin, HIGH);
  }

  else if (center == LOW) {
    // Move FORWARD
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    nozzle.write(90);
    digitalWrite(pumpPin, HIGH);
  }

  else {
    // STOP
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(pumpPin, LOW);
  }
}
