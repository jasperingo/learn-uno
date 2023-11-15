#include <LiquidCrystal_I2C.h>

const LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int playBtnPin = 4;

const int changeSongBtnPin = 2;

const int speakerPin = 10;

const int numberOfSongs = 2;

const int songLength = 28;

const int songTempos[] = { 300, 200 };

const String songs[] = { "Twinkle Twinkle", "Happy birthday" };

const int frequencies[][28] = {
  { 262, 0, 262, 0, 392, 0, 392, 0, 440, 0, 440, 0, 392, 0, 349, 0, 349, 0, 329, 0, 329, 0, 294, 0, 294, 0, 262, 0 },
  { 196, 196, 220, 196, 262, 247, 0, 196, 196, 220, 196, 294, 262, 0, 196, 196, 392, 330, 262, 247, 220, 0, 349, 349, 330, 262, 294, 262 }
};

const float beats[][28] = {
  { 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 2, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 1, 0.1, 2, 0.1 },
  { 2, 1, 4, 4, 4, 4, 2, 2, 1, 4, 4, 4, 4, 2, 2, 1, 4, 4, 4, 4, 6, 2, 2, 1, 4, 4, 4, 6 }
};

int playBtnPrevState = HIGH;

int changeSongBtnPrevState = HIGH;

int currentSong = 0;

bool shouldPlay = false;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(playBtnPin, INPUT_PULLUP);
  pinMode(changeSongBtnPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  printToLDC();
}

void loop() {
   int playBtnState = digitalRead(playBtnPin);
   int changeSongBtnState = digitalRead(changeSongBtnPin);

  if (playBtnPrevState == LOW && playBtnState == HIGH && !shouldPlay) {
    shouldPlay = true;
    playSong();
  } else if (changeSongBtnPrevState == LOW && changeSongBtnState == HIGH) {
    currentSong++;

    if ((currentSong + 1) > numberOfSongs) {
      currentSong = 0;
    }

    printToLDC();
  }

  playBtnPrevState = playBtnState;

  changeSongBtnPrevState = changeSongBtnState;
}

void playSong() {
  for (int i = 0; i < songLength; i++) {
    int duration = beats[currentSong][i] * songTempos[currentSong];
    tone(speakerPin, frequencies[currentSong][i], duration);
    delay(duration);
  }

  shouldPlay = false;
}

void printToLDC() {
  lcd.clear();
  lcd.print(songs[currentSong]);
}
