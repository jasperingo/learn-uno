const int lightPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(100);
}
