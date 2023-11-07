import processing.serial.*;
import processing.net.*;

Serial serial;
Client client;
String host = "127.0.0.1";

void setup() {
  size(400, 400);
  println(join(Serial.list(), ", "));
  serial = new Serial(this, "/dev/cu.usbmodem6", 9600);
  client = new Client(this, host, 32000);
  background(0);
  noStroke();
  fill(255);
}

void draw() {
  if (serial.available() > 0) {
    int value = serial.read();
    println(value);
    client.write(value);
  }
}
