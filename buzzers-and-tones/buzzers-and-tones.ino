const int speakerPin = 9;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  tone(speakerPin, 440, 500);
  delay(1000);
}
