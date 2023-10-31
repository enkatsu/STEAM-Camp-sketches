import processing.net.*;

Client client;
String host = "127.0.0.1";

void setup() {
  size(600, 600);
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
      String[] values = split(message, ' ');
      int x = parseInt(values[0]);
      int y = parseInt(values[1]);
      background(0);
      ellipse(x, y, 50, 50);
    }
  }
}

void mouseMoved() {
  if (frameCount % 2 == 0) {
    String message = mouseX + " " + mouseY + "\n";
    client.write(message);
  }
}
