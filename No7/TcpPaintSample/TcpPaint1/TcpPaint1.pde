import processing.net.*;

Client client;
String host = "127.0.0.1";


void setup() {
  size(600, 600);
  client = new Client(this, host, 32001);
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
      String command = values[0];
      if ("ellipse".equals(command)) {
        int x = parseInt(values[1]);
        int y = parseInt(values[2]);
        ellipse(x, y, 10, 10);
      } else if ("clear".equals(command)) {
        background(0);
      }
    }
  }
}

void mouseDragged() {
  ellipse(mouseX, mouseY, 10, 10);
  String message = "ellipse " + mouseX + " " + mouseY + "\n";
  client.write(message);
}

void keyPressed() {
  if (key == ' ') {
    background(0);
    String message = "clear\n";
    client.write(message);
  }
}
