const int pulsePin = 7;
const int triggerPin = 4;
const int positiveLedPin = 8;
const int negativeLedPin = 12;
const int trigDelay = 25;
const int negativeThreshold = 10;

void setup() {
  Serial.begin(9600);
  pinMode(positiveLedPin, OUTPUT);
  pinMode(negativeLedPin, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(trigDelay);
  digitalWrite(triggerPin, LOW);

  pinMode(pulsePin, INPUT);
  duration = pulseIn(pulsePin, HIGH);

  // convert time to distance
  distance = duration / 58.8;

  if (distance < negativeThreshold) {
    digitalWrite(positiveLedPin, LOW);
    digitalWrite(negativeLedPin, HIGH);
  } else {
    digitalWrite(negativeLedPin, LOW);
    digitalWrite(positiveLedPin, HIGH);
  }

  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
