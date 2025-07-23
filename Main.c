// Ultrasonic and Mic Pins
#define trigPin 5
#define echoPin 18
#define micPin 34

// First Set of Traffic Lights
#define redLED1 22
#define greenLED1 23

// Second Set of Traffic Lights (New Pins)
#define redLED2 27
#define greenLED2 26

long duration;
int distance;
int micValue;

// Thresholds
const int distanceThreshold = 50;       // cm
const int ambulanceSoundThreshold = 1800; // Analog value for ambulance siren

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(micPin, INPUT);

  // Set 1
  pinMode(redLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);

  // Set 2
  pinMode(redLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
}

void loop() {
  // --- Measure Distance ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // --- Read Mic ---
  micValue = analogRead(micPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Mic: ");
  Serial.println(micValue);

  // --- Priority Decisions ---
  if (micValue > ambulanceSoundThreshold) {
    setLights(HIGH, LOW);  // All green
    Serial.println("🚑 Ambulance - All Green");
  } else if (distance < distanceThreshold) {
    setLights(HIGH, LOW);  // All green
    Serial.println("🚗 Vehicle Detected - All Green");
  } else {
    setLights(LOW, HIGH);  // All red
    Serial.println("🔴 No Vehicle - All Red");
  }

  delay(300);
}

// Function to control both sets
void setLights(bool greenOn, bool redOn) {
  digitalWrite(greenLED1, greenOn);
  digitalWrite(redLED1, redOn);

  digitalWrite(greenLED2, greenOn);
  digitalWrite(redLED2, redOn);
}
