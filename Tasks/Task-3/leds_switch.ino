#define buttonPin = 7;
#define redLED = 11;
#define yellowLED = 12;
#define greenLED = 13;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(1500)
    digitalWrite(yellowLED, LOW);

    digitalWrite(greenLED, HIGH);
    delay(1500);
    digitalWrite(greenLED, LOW);
  }
}
