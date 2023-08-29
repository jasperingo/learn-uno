const int btnPin = 2;
const int ledPin = 6;

int btnState = HIGH;

int ledState = LOW;

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {
  int bs = digitalRead(btnPin);

  if (btnState == HIGH && bs == LOW) {
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    
    digitalWrite(ledPin, ledState);
  }

  btnState = bs;
}
