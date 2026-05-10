int sensorPin = A0;

int ledHijau = 2;
int ledMerah = 3;
int buzzer = 4;

void setup() {

  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if(sensorValue > 615) {

    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);

    tone(buzzer, 1000);

  }

  else {

    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);

    noTone(buzzer);

  }

  delay(500);
}