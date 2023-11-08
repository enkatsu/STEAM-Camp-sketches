int switchPin = 12;
int pValue = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
}

void loop() {
  int value = digitalRead(switchPin);
  if (pValue == HIGH && value == LOW) {
    Serial.write(1);
  }
  pValue = value;

  delay(100);
}
