import processing.serial.*;
import processing.net.*;

Serial serial;
Client client;
String host = "127.0.0.1";

void setup() {
  size(400, 400);
  println(join(Serial.list(), ", "));
  serial = new Serial(this, "ARDUINO_PORT", 9600);
  client = new Client(this, host, 32000);
  background(0);
  noStroke();
  fill(255);
}

void draw() {
  if (client.available() > 0) {
    int value = client.read();
    println(value);
    serial.write(value);
  }
}
