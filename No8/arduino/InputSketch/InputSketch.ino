
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int value = analogRead(A0) / 4;
  Serial.write(value);
  delay(100);
}
