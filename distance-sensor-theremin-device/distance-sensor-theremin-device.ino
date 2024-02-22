const int speakerPin = 9;
const int trigPin = 4;
const int pwPin = 7;
const int trigDelay = 25;

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(trigDelay);
  digitalWrite(trigPin, LOW);

  pinMode(pwPin, INPUT);
  duration = pulseIn(pwPin, HIGH);

  // convert time to distance
  distance = duration / 58.8;

  Serial.print(distance);
  Serial.println(" cm");

  float frequency = 14.003 * distance - 15.01;

  Serial.print(frequency);
  Serial.println(" Hz");

  tone(speakerPin, frequency);

  delay(100);
}
