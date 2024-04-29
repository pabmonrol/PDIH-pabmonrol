int button = 0;

void setup() {
	pinMode(12, LOW);
  	pinMode(13, LOW);
  	pinMode(7, INPUT);
}

void loop() {
	button = digitalRead(7);

	digitalWrite(13, !button);
	digitalWrite(12, button);
	digitalWrite(11, button);

}