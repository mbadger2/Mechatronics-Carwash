const int stepPin = 2;
const int dirPin = 3;

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
