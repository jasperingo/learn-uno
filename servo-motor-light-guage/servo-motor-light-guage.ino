#include <Servo.h>

const int lightPin = A0;

const int servoPin = 9;

const Servo servo;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(lightPin);

  Serial.println(lightVal);

  int pos = map(lightVal, 0, 1023, 0, 180);

  Serial.println(pos);

  servo.write(pos);

  delay(50);
}
