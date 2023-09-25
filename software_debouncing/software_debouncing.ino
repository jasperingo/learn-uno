const int btnPin = 2;
const int debounceDelay = 50;

int counter = 0;
int btnPrev = HIGH;
int btnState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  int btnRead = digitalRead(btnPin);

  if (btnRead != btnPrev) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay)) {
    if (btnRead != btnState) {
      btnState = btnRead;

      if (btnState == LOW) {
        Serial.println(++counter);
      }
    }
  }

  btnPrev = btnRead;
}
