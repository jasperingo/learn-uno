const int btnPin = 2;
const int ledPin = 6;

int btnPrev = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);
}

void loop() {
  int btnState = digitalRead(btnPin);

  if (btnPrev == LOW && btnState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  }

  btnPrev = btnState;
}
