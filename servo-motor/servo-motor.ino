#include <Servo.h>

const int servoPin = 9;

const Servo servo;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  servo.write(90);
  delay(1000);

  servo.write(180);
  delay(1000);

  servo.write(0);
  delay(1000);

  for (int pos = 0; pos <= 180; pos += 5) {
    servo.write(pos);
    delay(50);
  }
}
