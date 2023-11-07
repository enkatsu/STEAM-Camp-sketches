#include <Servo.h>

Servo servo;
int servoPin = 6;
int ledPin = 5;
int servoDelay = 30;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 255);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    action();
    clearBuffer();
  }
}

void action() {
  for (int i = 0; i <= 100; i++) {
    servo.write(i);
    delay(servoDelay);
  }
  delay(1000);
  for (int i = 100; i >= 0; i--) {
    servo.write(i);
    delay(servoDelay);
  }
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
