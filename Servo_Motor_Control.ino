#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0;
bool forward = true;

unsigned long startTime;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  startTime = millis();
}

void loop() {

  // Run the Sweep motion for 2 seconds
  if (millis() - startTime < 2000) {

    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);

    if (forward) {
      pos++;
      if (pos >= 180) {
        forward = false;
      }
    } else {
      pos--;
      if (pos <= 0) {
        forward = true;
      }
    }

    delay(10);
  }

  // After 2 seconds, hold all servos at 90 degrees
  else {

    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);

    while (true) {
      
    }
  }
}