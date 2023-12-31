#include <Servo.h>
Servo servo;
int servoPin = 6;
int ledPin = 5;
int servoDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 255);
  servo.attach(servoPin);
}

void loop() {
  if (Serial.available() > 0) {
    action();
    clearBuffer();
  }
}

void action() {
  for (int i = 0; i <= 180; i++) {
    servo.write(i);
    delay(servoDelay);
  }
  delay(1000);
  for (int i = 180; i >= 0; i--) {
    servo.write(i);
    delay(servoDelay);
  }
  delay(1000);
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
