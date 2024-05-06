#include <Servo.h>

#define TRIGGER_PIN 9
#define TRIGGER_ECHO 10
#define BUZZER_PIN 8
#define SERVO_PIN 3

long duration;
int distance;
int port = 9600;
Servo myServo;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(TRIGGER_ECHO, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(port);

  myServo.attach(SERVO_PIN);
}
void loop() {
  for (int i = 15; i <= 165; i++) {
    moveServoAndDistance(i);
  }
  for (int i = 165; i > 15; i--) {
    moveServoAndDistance(i);
  }
}

void updateBuzzer() {
  if (distance > 0 && distance <= 40) { 
    int frequency = map(distance, 0, 40, 2000, 100); 
    tone(BUZZER_PIN, frequency, 100);
  } else {
    noTone(BUZZER_PIN);
  }
}

int calculateDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(TRIGGER_ECHO, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void moveServoAndDistance(int angle) {
  myServo.write(angle);
  delay(30);
  distance = calculateDistance();
  updateBuzzer();
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
}