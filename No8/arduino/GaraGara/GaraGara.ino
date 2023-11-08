#include <Stepper.h>
int sp_speed;     //回転スピード
int sp_step = 1;  //ステップ数
int round_step = 400;

Stepper stepper(round_step, 11, 10, 9, 8);

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
  sp_speed = 50;  //回転スピード
  float startTime = millis();
  float endTime = 5000;  // 5秒間回転

  while (millis() - startTime < endTime) {
    stepper.setSpeed(sp_speed);
    stepper.step(sp_step);
  }

  startTime = millis();

  while (millis() - startTime < endTime) {
    stepper.setSpeed(sp_speed);
    stepper.step(-sp_step);
  }
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}