#include <Servo.h>
Servo servo;
int servoPin = 3;
int servoDelay = 30;
int moterSpeed = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
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
  moterSpeed = 255;
  analogWrite(5, moterSpeed);
  analogWrite(6, 0);
  delay(1000);
  for (int i = 100; i >= 0; i--) {
    servo.write(i);
    delay(servoDelay);
  }
  delay(5000);
  moterSpeed = 0;
  analogWrite(5, moterSpeed);
  analogWrite(6, 0);
  delay(2000);
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
