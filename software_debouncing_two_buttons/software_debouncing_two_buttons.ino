const int incrementBtnPin = 2;
const int decrementBtnPin = 4;
const int debounceDelay = 50;

int counter = 0;
int incrementBtnPrev = HIGH;
int incrementBtnState = HIGH;
int decrementBtnPrev = HIGH;
int decrementBtnState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(incrementBtnPin, INPUT_PULLUP);
  pinMode(decrementBtnPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  int incrementBtnRead = digitalRead(incrementBtnPin);
  int decrementBtnRead = digitalRead(decrementBtnPin);

  if (incrementBtnRead != incrementBtnPrev || decrementBtnRead != decrementBtnPrev) {
    lastDebounceTime = millis();
  }

  if (millis() > (lastDebounceTime + debounceDelay)) {
    if (incrementBtnRead != incrementBtnState) {
      incrementBtnState = incrementBtnRead;

      if (incrementBtnState == LOW) {
        Serial.println(++counter);
      }
    } else if (decrementBtnRead != decrementBtnState) {
      decrementBtnState = decrementBtnRead;

      if (decrementBtnState == LOW) {
        Serial.println(--counter);
      }
    }
  }

  incrementBtnPrev = incrementBtnRead;
  decrementBtnPrev = decrementBtnRead;
}
