

# 📏 Ultrasonic Distance Calculator with OLED Display

## 📡 Project Overview

This project implements a compact, real-time distance measuring tool using an **HC-SR04 Ultrasonic Sensor** interfaced with an **Arduino Nano**. The measured distance is displayed clearly on a **0.96-inch 128x64 I2C OLED (SSD1306)** screen.

Upon power-up, the device shows a custom welcome message: **"Distance Calculator by PROTOSAMIOT"** and then continuously updates the distance reading in centimeters every half second.

---

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
| --- | --- | --- |
| **Microcontroller** | 1 | Arduino Nano (or compatible ATmega328P board) |
| **Display** | 1 | 0.96" 128x64 I2C OLED Display (SSD1306) |
| **Sensor** | 1 | HC-SR04 Ultrasonic Sensor Module |
| **Wiring** | - | Jumper wires |

---

## 🔌 Wiring Diagram and Connections

The I2C OLED display uses the Nano's dedicated I2C pins (A4 and A5), providing a clean and reliable connection.

| Component | Pin Label | Connects to Arduino Nano Pin | Notes |
| --- | --- | --- | --- |
| **OLED Display** | **VCC** | **+5V** | Power |
| **OLED Display** | **GND** | **GND** | Ground |
| **OLED Display** | **SCL** (Clock) | **A5** | I2C Clock Pin |
| **OLED Display** | **SDA** (Data) | **A4** | I2C Data Pin |
| **HC-SR04** | **VCC** | **+5V** | Power |
| **HC-SR04** | **GND** | **GND** | Ground |
| **HC-SR04** | **Trig** | **D10** | Digital Pin 10 |
| **HC-SR04** | **Echo** | **D9** | Digital Pin 9 |

---

## 📚 Software and Libraries

This project requires the following two libraries, which must be installed using the Arduino IDE's **Library Manager** (Sketch > Include Library > Manage Libraries...):

1. **Adafruit GFX Library** (Core graphics library)
2. **Adafruit SSD1306 Library** (Driver library for the OLED display)


---

## 📧 Contact

* **GitHub:** [https://github.com/ProtoSamIoT](https://github.com/ProtoSamIoT)
* **YouTube:** [https://www.youtube.com/@protosamiot](https://www.youtube.com/@protosamiot)
