const int soilSensorPin = A0;
const int pumpPin = 8;
int threshold = 500;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

void loop() {
  int moistureValue = analogRead(soilSensorPin);
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    digitalWrite(pumpPin, HIGH);
    Serial.println("Pump ON - Watering Plant 🌱");
  } else {
    digitalWrite(pumpPin, LOW);
    Serial.println("Pump OFF - Soil Moist 🌧️");
  }

  delay(2000);
}
