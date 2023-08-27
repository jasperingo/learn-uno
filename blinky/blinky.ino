const int pin = 4;
const int delayDuration = 1000; // 1 second

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  digitalWrite(pin, HIGH);
  delay(delayDuration);
  digitalWrite(pin, LOW);
  delay(delayDuration);
}
