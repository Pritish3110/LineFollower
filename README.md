# 🛤️ Line Following Robot with Obstacle Detection

This project is a simple yet effective **Line Following Robot** built using an Arduino UNO, L298N motor driver, IR sensors, and an ultrasonic sensor. The robot is designed to follow a black line on the ground and stop or take action when an obstacle is detected in front of it.

<div align="center">

![GitHub stars](https://img.shields.io/github/stars/Pritish3110/LineFollower?style=social)
![GitHub forks](https://img.shields.io/github/forks/Pritish3110/LineFollower?style=social)
![GitHub issues](https://img.shields.io/github/issues/Pritish3110/LineFollower)
![GitHub last commit](https://img.shields.io/github/last-commit/Pritish3110/LineFollower)

</div>

---

## 📁 Project Structure

```
LineFollower/
├── LineFollower.ino      # Main Arduino code
├── circuit_diagram.png   # Wiring diagram
├── assets/              # Project images and documentation
├── libraries/           # Required Arduino libraries
└── README.md            # Project documentation
```

---

## 🚀 Features

- **Line Following**: Follows black tape using **2 IR sensors**
- **Obstacle Detection**: Detects obstacles ahead using an **ultrasonic sensor**
- **Dual Power System**: Uses **2x 18650 (7.4V) batteries** for reliable power
- **Safe Voltage Regulation**: Employs **capacitors** and **LM7805 voltage regulator**
- **Microcontroller**: Controlled using an **Arduino UNO**
- **Four-Wheel Drive**: Uses **4 BO motors with wheels** for stable movement
- **Motor Control**: Powered through an **L298N motor driver**

---

## 🔧 Components Required

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino UNO | 1 | Main microcontroller |
| BO Motors + Wheels | 4 | Movement (2 left, 2 right) |
| L298N Motor Driver | 1 | Motor control |
| IR Sensors | 2 | Line tracking (black line detection) |
| Ultrasonic Sensor (HC-SR04) | 1 | Obstacle detection |
| 18650 Batteries (7.4V) | 2 | Power supply |
| LM7805 Voltage Regulator | 1 | 5V stable output |
| Capacitors (100µF, 10µF) | 2 each | Power filtering and regulation |
| Wires, Breadboard, Acrylic Base | - | Assembly |

---

## ⚙️ Working Principle

### 1. Line Following Algorithm
The two IR sensors continuously monitor the surface beneath the robot. The logic works as follows:
- **Both sensors on black line**: Robot moves forward
- **Left sensor off line**: Robot turns right to correct course
- **Right sensor off line**: Robot turns left to correct course
- **Both sensors off line**: Robot stops or searches for line

### 2. Obstacle Detection System
The ultrasonic sensor measures distance to obstacles ahead:
- **Clear path**: Normal line following continues
- **Obstacle detected** (< 10cm): Robot stops or executes avoidance maneuver
- **Obstacle cleared**: Resume line following

### 3. Power Management System
- **Primary Power**: Two 18650 batteries in series provide 7.4V
- **Voltage Regulation**: LM7805 converts 7.4V to stable 5V
- **Power Distribution**: 
  - 7.4V → Arduino VIN and L298N 12V input
  - 5V regulated → IR sensors and ultrasonic sensor
- **Filtering**: Capacitors eliminate voltage fluctuations

---

## 🔌 Wiring Configuration

| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| IR Sensor (Left) | D2 | Left line detection |
| IR Sensor (Right) | D3 | Right line detection |
| Ultrasonic Trigger | D4 | Distance measurement trigger |
| Ultrasonic Echo | D5 | Distance measurement echo |
| Motor IN1 | D6 | Left motor control |
| Motor IN2 | D7 | Left motor control |
| Motor IN3 | D8 | Right motor control |
| Motor IN4 | D9 | Right motor control |
| ENA (Left PWM) | D10 | Left motor speed control |
| ENB (Right PWM) | D11 | Right motor speed control |

### Power Connections
- **7.4V Input**: Arduino VIN, L298N 12V terminal
- **5V Regulated**: IR sensors VCC, Ultrasonic sensor VCC
- **Ground**: Common ground for all components
- **Motors**: Connected to L298N OUT1–OUT4

⚠️ **Important**: Ensure proper grounding and use capacitors for voltage stability

---

## 🧠 Arduino Logic Flow

```
1. Initialize sensors and motors
2. Read IR sensors for line position
3. Check ultrasonic sensor for obstacles
4. Decision making:
   - If obstacle detected → Stop/Avoid
   - If both sensors detect line → Move forward
   - If left sensor off line → Turn right
   - If right sensor off line → Turn left
   - If both sensors off line → Search pattern
5. Execute motor commands
6. Repeat loop
```

---

## 🎯 Project Milestones

- [x] Design circuit layout and wiring
- [x] Implement basic line following algorithm
- [x] Add obstacle detection functionality
- [x] Integrate power management system
- [x] Test and calibrate sensor thresholds
- [x] Optimize motor control for smooth movement
- [ ] Add PID control for smoother line following
- [ ] Implement turning logic for intersections
- [ ] Add LCD or Bluetooth module for monitoring
- [ ] Expand to maze-solving capabilities

---

## 📷 Project Gallery

*Add images of your robot wiring, finished build, or circuit diagram here:*

- Circuit diagram and component layout
- Assembled robot construction
- Line following demonstration
- Obstacle detection testing

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE installed
- Basic understanding of Arduino programming
- Soldering skills (optional but recommended)

### Setup Steps

1. **Clone this repository**:
   ```bash
   git clone https://github.com/Pritish3110/LineFollower
   cd LineFollower
   ```

2. **Assemble the hardware** according to the wiring diagram

3. **Upload the code**:
   - Open `LineFollower.ino` in Arduino IDE
   - Select your Arduino board and port
   - Upload the code

4. **Calibrate sensors**:
   - Adjust IR sensor sensitivity
   - Test ultrasonic sensor range
   - Fine-tune motor speeds

5. **Test the robot**:
   - Create a black line track
   - Place obstacles for testing
   - Monitor performance and adjust as needed

---

## 🔧 Configuration & Tuning

### Sensor Calibration
```cpp
// IR sensor threshold values
#define LINE_THRESHOLD 500

// Ultrasonic sensor distance threshold
#define OBSTACLE_DISTANCE 10  // cm

// Motor speed settings
#define MOTOR_SPEED 150  // 0-255
```

### Performance Optimization
- Adjust motor speeds for different surfaces
- Fine-tune sensor thresholds for various lighting conditions
- Modify obstacle detection distance based on requirements

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

```
Copyright (c) 2024 Pritish Bhatasana

Licensed under the MIT License (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://opensource.org/licenses/MIT

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

---

## 🙏 Acknowledgments

<div align="center">

### **Special Thanks**

**Arduino Community**  
*For comprehensive documentation and extensive library support*

**Robotics & Maker Community**  
*For tutorials, troubleshooting guides, and innovative project ideas*

**Open Source Hardware Initiative**  
*For making affordable components and development platforms accessible*

---

### **Connect With Me**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/pritish-bhatasana)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Pritish3110)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:pritishbhatasana68@gmail.com)

---

### **Project Stats**

![Language](https://img.shields.io/badge/Language-C/C++-blue?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Arduino-green?style=for-the-badge)
![Type](https://img.shields.io/badge/Type-Line_Following-red?style=for-the-badge)

**Made with ❤️ for autonomous robotics and smart mobility**

</div>

---

## 📚 Additional Resources

- [Arduino IDE Documentation](https://www.arduino.cc/en/Guide/Environment)
- [L298N Motor Driver Tutorial](https://create.arduino.cc/projecthub/robocircuits/how-to-use-l298n-motor-driver-b124ac)
- [IR Sensor Interfacing Guide](https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial)
- [Ultrasonic Sensor HC-SR04 Tutorial](https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6)
- [Line Following Robot Algorithms](https://www.robotix.in/tutorial/category/auto/linefollower)
- [PID Control for Line Following](https://www.youtube.com/watch?v=4Y7zG48uHRo)

---

<div align="center">

**🚀 Ready to follow any line autonomously!**

*Built with intelligent sensors and robust control systems*

</div>
