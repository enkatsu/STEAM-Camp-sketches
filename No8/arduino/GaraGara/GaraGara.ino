#include <Stepper.h>

int spStep = 1;
int roundStep = 400;
int spSpeed = 50;

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
  float startTime = millis();
  float endTime = 5000;

  while (millis() - startTime < endTime) {
    stepper.setSpeed(spSpeed);
    stepper.step(spStep);
  }

  startTime = millis();

  while (millis() - startTime < endTime) {
    stepper.setSpeed(spSpeed);
    stepper.step(-spStep);
  }
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
