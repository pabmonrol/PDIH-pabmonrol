#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define BUZZER_PIN   8

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= 200) {
    tone(BUZZER_PIN, 1000 - (distance * 10), 100);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(100);
}