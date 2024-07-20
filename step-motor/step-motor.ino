#include <Stepper.h>

const int STEPS = 2048;

const Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(15);
}

void loop() {
  stepper.step(STEPS);
  delay(1000);

  stepper.step(-STEPS);
  delay(1000);
}
