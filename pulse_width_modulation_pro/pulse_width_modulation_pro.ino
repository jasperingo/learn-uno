const int ledPin1 = 3;
const int ledPin2 = 5;
const int ledPin3 = 6;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  for (int i = 0; i < 395; i++) {
    analogWrite(ledPin1, getBrightness(i));
    analogWrite(ledPin2, getBrightness(i - 70));
    analogWrite(ledPin3, getBrightness(i - 140));

    delay(10);
  }
}

int getBrightness(const int brightness) {
  if (brightness < 0) {
    return 0;
  } else if (brightness > 255) {
    return 255;
  } else {
    return brightness;
  }
}
