const int redPins[3] = {5, 9, 11};

const int bluePins[3] = {3, 6, 10};

const int ledColorBtnPin = 2;

const int brightnessBtnPin = 13;

int ledColorBtnPrevState = HIGH;

int brightnessBtnPrevState = HIGH;

int brightness = 1;

int ledType = 0;

void setup() {
  pinMode(ledColorBtnPin, INPUT_PULLUP);
  pinMode(brightnessBtnPin, INPUT_PULLUP);

  for (int i = 0; i < 3; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(bluePins[i], OUTPUT);
  }
}

void loop() {
  toggleLed();
  changeBrightness();
}

void changeBrightness() {
   const int btnState = digitalRead(brightnessBtnPin);

  if (btnState != brightnessBtnPrevState && btnState == LOW) {
    brightness *= 4;
  
    if (brightness > 255) {
      brightness = 1;
    }

    for (int i = 0; i < 3; i++) {
      if (ledType == 1 || ledType == 0) {
        analogWrite(redPins[i], brightness);
      }

      if (ledType == 2 || ledType == 0) {
        analogWrite(bluePins[i], brightness);
      }
    }
  }

  brightnessBtnPrevState = btnState;
}

void toggleLed() {
  const int btnState = digitalRead(ledColorBtnPin);

  if (btnState != ledColorBtnPrevState && btnState == LOW) {
    ledType += 1;

    if (ledType > 2) {
      ledType = 0;
    }

    for (int i = 0; i < 3; i++) {
      if (ledType == 2) {
        analogWrite(redPins[i], 0);
        analogWrite(bluePins[i], brightness);
      } else if (ledType == 1) {
        analogWrite(bluePins[i], 0);
      } else {
        analogWrite(redPins[i], brightness);
        analogWrite(bluePins[i], brightness);
      }
    }
  }

  ledColorBtnPrevState = btnState;
}
