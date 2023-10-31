import processing.serial.*;
import processing.net.*;

Serial serial;
Client client;
String host = "127.0.0.1";

void setup() {
  size(600, 600);
  println(join(Serial.list(), ", "));
  serial = new Serial(this, "your arduino port", 9600);
  client = new Client(this, host, 32000);
  background(0);
  noStroke();
  fill(255);
}

void draw() {
  if (client.available() > 0) {
    String message = client.readStringUntil('\n');
    if (message != null) {
      message = trim(message);
      int value = parseInt(message);
      serial.write(value);
    }
  }
}
