const int btnPin = 2;

int btnPrev = HIGH;

int counter = 0;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int btnState = digitalRead(btnPin);

  if (btnPrev == LOW && btnState == HIGH) {
    Serial.println(++counter);
  }

  btnPrev = btnState;
}
