# ESP32 Ultrasonic Radar System

## 📡 Project Overview
This project demonstrates a **radar system using ESP32**, an ultrasonic sensor, a TFT display, and a buzzer.  
The radar is displayed in a **circular format**, showing the real-time position of objects detected by the ultrasonic sensor with a smooth glowing sweep animation.

When an object enters the defined range:
- The object is plotted on the radar
- A buzzer alerts the user
- Live object position is visualized on the TFT display

---

## 🛠 Components Used
- ESP32 Development Board (38-Pin)
- Ultrasonic Sensor (HC-SR04)
- TFT Display (8-Pin SPI – ILI9341)
- Buzzer
- Resistors (1kΩ + 2kΩ for voltage divider)
- Jumper Wires
- Breadboard

---

## 🔌 Connections

### Ultrasonic Sensor (HC-SR04)
| HC-SR04 | ESP32 |
|-------|------|
| VCC | 5V |
| GND | GND |
| TRIG | GPIO 26 |
| ECHO | GPIO 25 *(via voltage divider)* |

⚠️ HC-SR04 ECHO outputs **5V**. ESP32 supports **3.3V only**.  
Use a voltage divider:

---

### Buzzer
| Buzzer | ESP32 |
|-------|------|
| + | GPIO 27 |
| - | GND |

---

### TFT Display (SPI – ILI9341)
| TFT | ESP32 |
|------|------|
| VCC | 3.3V |
| GND | GND |
| CS | GPIO 5 |
| RESET | GPIO 4 |
| DC | GPIO 2 |
| MOSI | GPIO 23 |
| SCK | GPIO 18 |
| LED | 3.3V |

---

## 📚 Libraries Required
Install from Arduino Library Manager:
- Adafruit GFX Library
- Adafruit ILI9341
- SPI

---

## ▶️ How It Works
1. ESP32 triggers the ultrasonic sensor
2. Distance is calculated using echo time
3. Circular radar grid is drawn on the TFT
4. A glowing sweep line scans from 0° to 180°
5. Detected objects are plotted in real time
6. Buzzer alerts when an object enters the range

---

## 🎥 Demo & Tutorials
📺 YouTube: https://www.youtube.com/@protosamiot  
💻 GitHub: https://github.com/ProtoSamIoT

---

## ⭐ Support
If you like this project:
- ⭐ Star the repository
- 🔔 Subscribe to the YouTube channel
- 🔁 Share it with fellow makers
