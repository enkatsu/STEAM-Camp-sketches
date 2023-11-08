int speeds = 255;
int aInPin1 = 11;
int aInPin2 = 12;
int bInPin1 = 8;
int bInPin2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(aInPin1, OUTPUT);
  pinMode(aInPin2, OUTPUT);
  pinMode(bInPin1, OUTPUT);
  pinMode(bInPin2, OUTPUT);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    rotateFun();
    clearBuffer();
  }
}

void rotateFun() {
  analogWrite(aInPin1, speeds);
  analogWrite(aInPin2, 0);
  analogWrite(bInPin1, speeds);
  analogWrite(bInPin2, 0);
  delay(1000);
  analogWrite(aInPin1, 0);
  analogWrite(aInPin2, 0);
  analogWrite(bInPin1, 0);
  analogWrite(bInPin2, 0);
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
