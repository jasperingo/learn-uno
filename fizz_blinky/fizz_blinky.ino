int counter = 1;
const int ledPin = 2;
const int delayDuration = 500;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if ((counter % 3) == 0) {
    digitalWrite(ledPin, HIGH);
    delay(delayDuration);
    digitalWrite(ledPin, LOW);
  } else {
    Serial.println(counter);
  }
  
  counter += 1;

  delay(delayDuration);
}
