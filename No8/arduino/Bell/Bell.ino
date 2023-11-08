#include <Servo.h>
Servo servo;
int servoPin = 3;
int servoDealy = 20;

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
  for (int i = 0; i <= 180; i++) {
    servo.write(i);
    delay(servoPin);
  }
  delay(1000);
  for (int i = 180; i >= 0; i--) {
    servo.write(i);
    delay(servoDealy);
  }
  delay(1000);
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
