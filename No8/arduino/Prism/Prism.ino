#include <Stepper.h>
int speed = 10;
int step = 1;
int roundStep = 400;
Stepper stepper(roundStep, 11, 10, 9, 8);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    action();
    clearBuffer();
  }
}

void action() {
  for (int i = 0; i <= 180; i++) {
    stepper.setSpeed(speed);
    stepper.step(step);
    delay(10);
  }
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
