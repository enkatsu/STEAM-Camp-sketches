const uint8_t speeds = 255;
int AinPin1 = 11;
int AinPin2 = 12;
int BinPin1 = 8;
int BinPin2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(AinPin1, OUTPUT);
  pinMode(AinPin2, OUTPUT);
  pinMode(BinPin1, OUTPUT);
  pinMode(BinPin2, OUTPUT);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    rotateFun();
    clearBuffer();
  }
}

void rotateFun() {
  analogWrite(AinPin1, speeds);
  analogWrite(AinPin2, 0);
  analogWrite(BinPin1, speeds);
  analogWrite(BinPin2, 0);
  delay(1000);
}

void clearBuffer() {
  int bufferLength = Serial.available();
  for (int i = 0; i < bufferLength; i++) {
    Serial.read();
  }
}
