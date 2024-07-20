// Steinhart–Hart equation constants
const float C1 = 1.009249522e-03;
const float C2 = 2.378405444e-04;
const float C3 = 2.019202697e-07;

// Known resistance
const float R1 = 10000;

const int ledPin = 8;
const int thermistorPin = A0;

int volatage;
float R2;
float logR2;
float temperature;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  volatage = analogRead(thermistorPin);
  Serial.print("Analog volatage: "); 
  Serial.println(volatage);

  Serial.print("Calc volatage: "); 
  Serial.println(volatage * 5.0 / 1023);

  R2 = R1 * (1023.0 / (float)volatage - 1.0);

  Serial.print("Resistance: "); 
  Serial.println(R2);

  logR2 = log(R2);

  temperature = (1.0 / (C1 + (C2 * logR2) + (C3 * logR2 * logR2 * logR2)));

  Serial.print("Temperature: "); 
  Serial.print(temperature);
  Serial.print(" K ");

  temperature = temperature - 273.15;

  if (temperature >= 20) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  Serial.print(temperature);
  Serial.print(" C ");

  temperature = (temperature * 9.0) / 5.0 + 32.0;

  Serial.print(temperature);
  Serial.println(" F"); 
  Serial.println(""); 

  delay(1000);
}
