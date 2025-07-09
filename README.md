# 🛤️ Line Following Robot with Obstacle Detection

This project is a simple yet effective **Line Following Robot** built using an Arduino UNO, L298N motor driver, IR sensors, and an ultrasonic sensor. The robot is designed to follow a black line on the ground and stop or take action when an obstacle is detected in front of it.

---

## 🚀 Features

- Follows black tape using **2 IR sensors**
- Detects obstacles ahead using an **ultrasonic sensor**
- Dual power source using **2x 18650 (7.4V) batteries**
- Safe voltage regulation using **capacitors** and **LM7805 voltage regulator**
- Controlled using an **Arduino UNO**
- Uses **4 BO motors with wheels** for movement
- Powered through an **L298N motor driver**

---

## 🔧 Components Used

| Component              | Quantity | Purpose                                  |
|------------------------|----------|------------------------------------------|
| Arduino UNO            | 1        | Main controller                          |
| BO Motors + Wheels     | 4        | Movement (2 left, 2 right)               |
| L298N Motor Driver     | 1        | Motor control                            |
| IR Sensors             | 2        | Line tracking (black line detection)     |
| Ultrasonic Sensor (HC-SR04) | 1    | Obstacle detection                       |
| 18650 Batteries (7.4V) | 2        | Power supply                             |
| LM7805 Voltage Regulator | 1     | 5V stable output                         |
| Capacitors (100µF, 10µF) | 2 each | Power filtering and regulation           |
| Wires, Breadboard, Acrylic Base | - | Assembly                                 |

---

## ⚙️ Working Principle

1. **Line Following**:  
   The two IR sensors continuously check the surface. When both sensors are on the black line, the robot moves forward. If the line veers left or right, the robot adjusts its direction accordingly.

2. **Obstacle Detection**:  
   The ultrasonic sensor measures distance to obstacles. If an object is detected within a certain threshold (e.g. 10 cm), the robot stops or takes an alternate action.

3. **Power System**:  
   The system is powered by two 18650 batteries in series (7.4V). A **LM7805 voltage regulator** is used to deliver a safe and stable 5V output to the Arduino and sensors. Capacitors smooth out the voltage fluctuations.

---

## 🔌 Wiring Overview

- **IR Sensors**: Connected to digital pins (e.g., D2 and D3)
- **Ultrasonic Sensor**: Trigger and Echo pins to digital pins (e.g., D4 and D5)
- **L298N**: Connected to 4 digital pins for IN1-IN4 and PWM pins for ENA and ENB
- **Motors**: Connected to L298N OUT1–OUT4
- **Power Supply**:
  - 7.4V → VIN of Arduino and 12V input of L298N
  - LM7805 → 5V regulated output to IR sensors and ultrasonic sensor

---

## 🧠 Arduino Logic Summary

- Read IR sensors to determine line position
- Use conditional logic to:
  - Move forward
  - Turn left/right
  - Stop if off the line
- Read ultrasonic sensor
  - Stop or avoid obstacle if detected

---

## 🖼️ Future Improvements

- Add PID control for smoother line following
- Implement turning logic for intersections
- Add LCD or Bluetooth module for monitoring
- Expand to a maze-solving robot

---

## 🛠️ Author

**Pritish Bhatasana**  
Inspired by smart mobility and real-time robotics  
GitHub: [Pritish3110](https://github.com/Pritish3110)

---

## 📄 License

This project is open-source and free to use under the [MIT License](LICENSE).
