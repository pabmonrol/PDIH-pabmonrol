int button = 0;

void setup() {
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(7, INPUT);
}

void loop() {
    int button = digitalRead(7);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(1500);
    
    if (button == HIGH) {
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
    	delay(1500);
    } else {
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
    	delay(1500);
        digitalWrite(13, LOW);
    }
    
}