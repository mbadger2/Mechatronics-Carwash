const int stepPin = 3;
const int dirPin = 4;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(dirPin, HIGH);
}

void loop() {
  digitalWrite(stepPin, HIGH);
  delay(1);

  digitalWrite(stepPin, LOW);
  delay(1);
}