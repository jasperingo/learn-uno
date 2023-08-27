const int firstPin = 2;
const int secondPin = 3;
const int thirdPin = 4;
const int delayDuration = 500;

void setup() {
  pinMode(firstPin, OUTPUT);
  pinMode(secondPin, OUTPUT);
  pinMode(thirdPin, OUTPUT);
}

void loop() {
  blink(firstPin);

  for (int i = 0; i < 2; i++) {
    blink(secondPin);
  }

  for (int i = 0; i < 3; i++) {
    blink(thirdPin);
  }
}

void blink(const int pin) {
  digitalWrite(pin, HIGH);
  delay(delayDuration);
  digitalWrite(pin, LOW);
  delay(delayDuration);
}
