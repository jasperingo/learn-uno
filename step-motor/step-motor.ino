#include <Stepper.h>

const int STEPS = 2048;

Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
}

void loop() {
  // get the sensor value
  // int val = 200;

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(STEPS);
  delay(1000);

  stepper.step(-STEPS);
  delay(1000);

  // remember the previous value of the sensor
  // previous = val;
}
