# 🏠 SmartHome – IoT Based Home Automation System

**SmartHome** is an Internet of Things (IoT) project built under the *Software Development* subject during college. It demonstrates a working miniature model of a smart home that allows users to control appliances like **lights**, **fans**, and a **security camera** remotely via a **mobile app** or **web interface**.

---

## 🎯 Project Purpose

This project aims to offer a seamless and efficient way to manage home appliances remotely, regardless of time and location, using Wi-Fi and sensor-based automation.

---

## 📌 Features

- 🔌 Control lights and fans through a phone app or web interface
- 👁️ Motion-triggered security camera using ESP32-CAM
- 📱 Android-based app interface (Blynk)
- ⚡ Real-time appliance control via relay modules
- 🔧 Complete Arduino-based circuit design and programming
- 🧪 Includes test cases, scenarios, and documentation
- 🌐 Offline circuit also supported (no Wi-Fi for basic mode)

---

## 🛠️ Technologies & Components

- **Arduino UNO** (Microcontroller)
- **ESP32-CAM** (for security & image capture)
- **PIR Sensor** (motion detection)
- **2-Channel Relay Module** (appliance control)
- **FTDI 232 Module** (for ESP32-CAM programming)
- **Blynk App** (IoT dashboard)
- **HTML, CSS, JavaScript** (for optional web interface)

---

## ⚙️ How It Works

### Part 1: Light & Fan Control
- Motion detected by PIR sensor
- Arduino sends signal to relay module
- Appliances are toggled ON/OFF automatically

### Part 2: Security System
- ESP32-CAM connected to PIR sensor via a transistor circuit
- Captures images on motion detection
- Controlled and monitored via the Blynk app

---

## 🚀 Setup Instructions

1. Upload Arduino and ESP32-CAM code using Arduino IDE
2. Connect components as per the circuit diagrams
3. Configure Blynk app and use the provided Auth Token in your code
4. Power the circuit and use the app/web to control or monitor your devices

---

## 📈 Large-Scale Implementation Notes

While this model uses Arduino UNO (with limited power/current capacity), it can be scaled using more powerful components like **Arduino Mega**, **Raspberry Pi**, and commercial-grade sensors and relays.

---

## 👩‍💻 Developer

- **Saumya Gangwar**
- Developed as part of a college course on Software Development

---

## 💡 Future Improvements

- Voice control integration (Google Assistant, Alexa)
- Cloud-based logging and analytics
- Full web dashboard for control and monitoring
- Advanced motion tracking and alerts
