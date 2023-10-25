#include <LiquidCrystal_I2C.h>

const LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int jumpBtn = 4;

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

const byte rock[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};

const int personPositionX = 5;

int rockPositionX = 10;

int personPositionY = 1;

int jumpBtnPrevState = HIGH;

long timeOfJump = 0; // seconds

long timeOfRockMove = 0; // seconds

bool gameOver = false;

void setup() {
  pinMode(jumpBtn, INPUT_PULLUP);

  lcd.init();                     
  lcd.backlight();
  lcd.createChar(0, person);
  lcd.createChar(1, rock);
  printGameCharacters();
}

void loop() {
  const int btnState = digitalRead(jumpBtn);

  const long currentSecond = millis() / 1000;

  if (btnState != jumpBtnPrevState && btnState == LOW) {
    if (gameOver) {
      gameOver = false;
      rockPositionX = 10;
      timeOfJump = 0;
      timeOfRockMove = 0;
      printGameCharacters();
    } else if (personPositionY == 1) {
      personPositionY = 0;
      timeOfJump = currentSecond;
      printGameCharacters();
    }
  } else if (!gameOver && personPositionY == 0 && (currentSecond - timeOfJump) > 1) {
    timeOfJump = 0;
    personPositionY = 1;
    printGameCharacters();
  }
  
  const long currentHalfSecond = millis() / 500;

  if (!gameOver && (currentHalfSecond - timeOfRockMove) >= 1) {
    rockPositionX--;
    timeOfRockMove = currentHalfSecond;

    if (rockPositionX < 0) {
      rockPositionX = 10;
    }

    if (rockPositionX == personPositionX && personPositionY == 1) {
      gameOver = true;
      printGameOver();
    } else {
      printGameCharacters();
    }
  }

  jumpBtnPrevState = btnState;
}

void printGameCharacters() {
  lcd.clear();
  lcd.setCursor(personPositionX, personPositionY);
  lcd.write(byte(0));
  lcd.setCursor(rockPositionX, 1);
  lcd.write(byte(1));
}

void printGameOver() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Game Over!");
}
