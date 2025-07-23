
# Smart Traffic Light Controller – ESP32 Based

This project is a basic implementation of a smart traffic signal system using an **ultrasonic distance sensor** and a **microphone** connected to an **ESP32**. The system detects the presence of a vehicle or an ambulance siren sound and controls two sets of traffic lights accordingly.

---

## Features

- Detects nearby vehicles using an ultrasonic sensor.
- Detects ambulance sirens using a mic module.
- Automatically turns both traffic signals green when a vehicle or ambulance is detected.
- Keeps both signals red when no vehicle is nearby and no emergency sound is detected.
- Simple logic for testing and demonstration purposes.

---

## Hardware Used

- ESP32 Dev Board
- HC-SR04 Ultrasonic Sensor
- Analog Microphone Sound Sensor
- 4 LEDs (2 red, 2 green) for traffic signals
- Jumper wires and breadboard

---

## Pin Connections

| Component        | ESP32 Pin |
|------------------|-----------|
| HC-SR04 Trigger  | D5        |
| HC-SR04 Echo     | D18       |
| Microphone       | D34       |
| Red LED Set 1    | D22       |
| Green LED Set 1  | D23       |
| Red LED Set 2    | D27       |
| Green LED Set 2  | D26       |

---

## How It Works

- The ultrasonic sensor checks the distance from a potential vehicle.
- The mic listens for loud sirens (like those from ambulances).
- If either a nearby object (within 50 cm) or a loud siren is detected (mic value > 1800), all signals turn green.
- If not, all signals stay red.
- The distance and mic values are printed to the serial monitor for debugging.

---

## Code Overview

The main logic checks both mic and distance input every 300ms and sets the signal LEDs accordingly.

```cpp
if (micValue > ambulanceSoundThreshold) {
  setLights(HIGH, LOW);  // Green ON, Red OFF
} else if (distance < distanceThreshold) {
  setLights(HIGH, LOW);  // Green ON, Red OFF
} else {
  setLights(LOW, HIGH);  // Red ON, Green OFF
}
````

The `setLights()` function updates both signal sets at once.

---

## Sample Serial Output

```
Distance: 35 cm | Mic: 1900
🚑 Ambulance - All Green

Distance: 42 cm | Mic: 800
🚗 Vehicle Detected - All Green

Distance: 120 cm | Mic: 300
🔴 No Vehicle - All Red
```

---

## Future Ideas

* Add IR sensor to classify emergency vs. normal vehicles.
* Add WiFi-based logging or control.
* Use real traffic signal modules for demo purposes.

---




