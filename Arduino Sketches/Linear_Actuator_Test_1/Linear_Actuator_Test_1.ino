
const int buttonPin = 31;
const int potPin = A0;

const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9;

// Direction state
bool direction = false;

// Button debounce
bool lastButtonReading = HIGH;
bool buttonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Read pushbutton
  bool reading = digitalRead(buttonPin);

  // Debounce button
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      // Toggle direction when pressed
      if (buttonState == LOW) {
        direction = !direction;
      }
    }
  }

  lastButtonReading = reading;

  // Read potentiometer
  int potValue = analogRead(potPin);

  // Convert potentiometer reading to PWM
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Set motor direction
  if (direction == false) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }

  // ACTUAL MOTOR SPEED CONTROL
  analogWrite(ENA, motorSpeed);

  // Serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);

  Serial.print(" | Motor PWM: ");
  Serial.print(motorSpeed);

  Serial.print(" | Direction: ");
  Serial.println(direction ? "Retract" : "Extend");

  delay(10);
}
