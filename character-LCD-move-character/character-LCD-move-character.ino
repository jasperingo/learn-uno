#include <LiquidCrystal_I2C.h>

const LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int leftBtn = 4;

const int rightBtn = 8;

const byte person[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01010,
  B01010,
  B00000
};

int cursorX = 0;

int cursorY = 0;

int leftBtnPrevState = HIGH;

int rightBtnPrevState = HIGH;

void setup() {
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);

  lcd.init();                     
  lcd.backlight();
  lcd.createChar(0, person);
  printToLcd();
}

void loop() {
  moveLeft();
  moveRight();
}

void printToLcd() {
  lcd.clear();
  lcd.setCursor(cursorX, cursorY);
  lcd.write(byte(0));
}

void changeCursorY() {
  if (cursorY == 0) {
    cursorY = 1;
  } else {
    cursorY = 0;
  }
}

void moveLeft() {
   const int btnState = digitalRead(leftBtn);

  if (btnState != leftBtnPrevState && btnState == LOW) {
    cursorX--;

    if (cursorX < 0) {
      cursorX = 15;
      changeCursorY();
    }

    printToLcd();
  }

  leftBtnPrevState = btnState;
}

void moveRight() {
  const int btnState = digitalRead(rightBtn);

  if (btnState != rightBtnPrevState && btnState == LOW) {
    cursorX++;

    if (cursorX > 15) {
      cursorX = 0;
      changeCursorY();
    }

    printToLcd();
  }

  rightBtnPrevState = btnState;
}

