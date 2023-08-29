const int btnPin = 2;

int btnPrev = HIGH;

int counter = 0;

void setup() {
  pinMode(btnPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  int btnState = digitalRead(btnPin);

  if (btnPrev == HIGH && btnState == LOW) {
    Serial.println(++counter);
  }

  btnPrev = btnState;
}
