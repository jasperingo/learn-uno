const int analogPin = A0;

const int btnPin = 2;

int btnPrevState = LOW;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  const int btnState = digitalRead(btnPin);

  if (btnState != btnPrevState && btnState == LOW) {
    const int value = analogRead(analogPin);

    const float voltage = (value * 5.0) / 1023;

    Serial.println(voltage);
  }

  btnPrevState = btnState;
}
