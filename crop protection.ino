// Pin definitions
int ENA = 9;      // Enable pin of L298N
int IN1 = 8;      // Motor input 1
int IN2 = 7;      // Motor input 2
int rainSensorPin = A0; 
int rainThreshold = 400;
int rainValue = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(rainSensorPin, INPUT);
  Serial.begin(9600);
  Serial.println("Horizontal Crop Cover System Started");
}

void loop() {
  rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < rainThreshold) {
    Serial.println("Rain detected! Closing cover...");
    moveCoverForward(); // Extend cover horizontally
    delay(3000);        // Time to fully close (adjust as needed)
    stopMotor();
  } else {
    Serial.println("No rain. Opening cover...");
    moveCoverBackward(); // Retract cover horizontally
    delay(3000);         // Time to fully open (adjust as needed)
    stopMotor();
  }
  delay(1000);
}

void moveCoverForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // Speed (0-255)
}

void moveCoverBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
