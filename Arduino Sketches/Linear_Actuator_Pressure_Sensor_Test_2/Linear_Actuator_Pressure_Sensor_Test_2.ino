
const int pressurePin = A2;

const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9;

// Adjustable sensor parameters
const int neutral = 950;
const int deadband = 10;
const int upperBound = 1020;
const int lowerBound = 800;


// Above Upper Bound (Highest Pressure)
//    - Max extend
// Between Upper Bound & Neutral + Deadband
//    - Adjustable extend
// Neutral +/- Deadband
//    - Stopped
// Between Lower Bound & Neutral - Deadband
//    - Adjustable retract
// Below Bound (Lowest Pressure)
//    - Max retract

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Read pressure sensor
  int pressureValue = analogRead(pressurePin);

  // Clamp sensor reading to upper and lower bounds
  pressureValue = constrain(pressureValue, lowerBound, upperBound);

  // Calculate distance from neutral
  int difference = abs(pressureValue - neutral);

  int motorSpeed = 0;

  // Above neutral: Extend
  if (pressureValue > neutral + deadband) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    motorSpeed = map(difference, deadband, upperBound - neutral, 0, 255);
  }

  // Below neutral: Retract
  else if (pressureValue < neutral - deadband) {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    motorSpeed = map(difference, deadband, neutral - lowerBound, 0, 255);
  }

  // Neutral: Stop
  else {
    motorSpeed = 0;
  }

  // Apply motor speed
  analogWrite(ENA, constrain(motorSpeed, 0, 255));

  // Serial monitor
  Serial.print("Pressure: ");
  Serial.print(pressureValue);

  Serial.print(" | Difference: ");
  Serial.print(difference);

  Serial.print(" | Motor PWM: ");
  Serial.print(motorSpeed);

  Serial.print(" | Direction: ");

  if (pressureValue > neutral + deadband) {
    Serial.println("Extend");
  }
  else if (pressureValue < neutral - deadband) {
    Serial.println("Retract");
  }
  else {
    Serial.println("Stopped");
  }

  delay(10);
}
