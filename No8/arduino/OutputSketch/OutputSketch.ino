#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(7, 500, 2400);
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.read();
    int angle = map(value, 0, 255, 0, 180);
    myServo.write(angle);
  }
}
