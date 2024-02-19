const int ledPin = 3;
const int lightPin = A0;

const int darknessThreshold = 100;

int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int lightVal = analogRead(lightPin);

  if (lightVal < darknessThreshold) {
    brightness = brightness >= 255 ? 255 : brightness + 15;
    analogWrite(ledPin, brightness);
  } else {
    brightness = 0;
    analogWrite(ledPin, brightness);
  }

  delay(50);
}
