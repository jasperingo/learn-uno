const int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  const int value = analogRead(analogPin);

  const float voltage = (value * 5.0) / 1023;

  Serial.println(voltage);

  delay(500);
}
