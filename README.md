# 🌟 GlowGrid-AI

### AI-Based Smart Street Light Monitoring, Fault Detection & Women's Safety SOS System

---

## 🚀 Overview

**GlowGrid-AI** is an intelligent smart-city solution designed to transform traditional street lighting infrastructure into a **smart, efficient, responsive, and safer urban network**.

By integrating **Artificial Intelligence (AI), Internet of Things (IoT), LoRa communication, and real-time monitoring**, the system continuously monitors street light performance, detects faults, optimizes maintenance operations, and supports public safety through an emergency SOS feature.

GlowGrid-AI aims to reduce energy wastage, improve infrastructure reliability, and contribute to safer communities.

---

## 💡 Key Features

### ✨ Real-Time Street Light Monitoring

* Continuous monitoring of street light status
* Voltage and current measurement
* Detection of abnormal operating conditions
* Live operational data collection

### ⚡ Intelligent Fault Detection

* Detects lamp failures
* Identifies power supply issues
* Monitors abnormal power consumption
* Enables faster maintenance response

### 📡 Long-Range LoRa Communication

* Low-power wireless communication
* Reliable long-distance data transmission
* Suitable for city-wide deployments
* Reduced infrastructure costs

### 🧠 AI-Driven Insights

* Predictive maintenance analysis
* Failure trend identification
* Energy usage optimization
* Infrastructure performance analytics

### 🌍 Smart City Integration

* Centralized monitoring capabilities
* Scalable deployment architecture
* Future-ready IoT infrastructure
* Supports urban digital transformation

---

## 🆘 Women's Safety SOS Feature

GlowGrid-AI extends beyond infrastructure monitoring by incorporating a Women's Safety Emergency Alert System.

### 🚨 Emergency SOS Activation

* SOS button installed on street light poles
* Immediate emergency alert generation
* Quick access during unsafe situations

### 📍 Location-Based Emergency Reporting

* Identifies nearest street light node
* Provides accurate emergency location
* Assists responders in locating incidents quickly

### 📡 Instant Alert Transmission

* Emergency alerts transmitted through LoRa network
* Reliable communication during emergencies
* Supports rapid response mechanisms

### 💡 Emergency Visual Signaling

* Nearby street lights can flash automatically
* Improves visibility of emergency location
* Assists security personnel and first responders

### ☁️ Central Monitoring & Notification

* Real-time alert display on monitoring dashboard
* Notification support for security personnel
* Event logging and response tracking

---

## 🛠️ Hardware Components

### Main Controller

* ESP32 Development Board

### Sensors

* ACS712 Current Sensor
* ZMPT101B Voltage Sensor

### Communication

* LoRa E220 Module

### Safety Components

* SOS Push Button
* Emergency Indicator LEDs/Buzzer (Optional)

### Load

* Street Light / Lamp

---

## 💻 Software & Technologies

* Arduino IDE
* Embedded C/C++
* ESP32 Framework
* LoRa Communication Protocol
* IoT System Architecture
* AI/ML Analytics (Future Scope)

---

## 🔌 Hardware Connections

| Component       | ESP32 Pin |
| --------------- | --------- |
| ACS712 Output   | GPIO34    |
| ZMPT101B Output | GPIO35    |
| LoRa TX         | GPIO17    |
| LoRa RX         | GPIO16    |
| LoRa M0         | GPIO25    |
| LoRa M1         | GPIO26    |
| LoRa AUX        | GPIO27    |
| SOS Button      | GPIO33    |
| Status LED      | GPIO2     |
| VCC             | 3.3V / 5V |
| GND             | GND       |

---

## 🧩 System Architecture

```text
                 STREET LIGHT NODE

          ┌──────────────────────┐
          │    Street Light      │
          └──────────┬───────────┘
                     │
         ┌───────────┴───────────┐
         │                       │
   ┌──────────┐           ┌──────────┐
   │ ACS712   │           │ ZMPT101B │
   │ Current  │           │ Voltage  │
   └────┬─────┘           └────┬─────┘
        │                      │
        └──────────┬───────────┘
                   │
               ┌───────┐
               │ ESP32 │
               └───┬───┘
                   │
            ┌──────┴──────┐
            │ LoRa E220   │
            └──────┬──────┘
                   │
         Long Range Communication
                   │
      ┌────────────┴────────────┐
      │ Central Monitoring Unit │
      └────────────┬────────────┘
                   │
              Dashboard
```

---

## 🔄 Working Principle

### Street Light Monitoring

1. Voltage sensor measures power supply status.
2. Current sensor measures load current.
3. ESP32 processes sensor readings.
4. System determines light status.
5. Fault conditions are identified.
6. Data is transmitted via LoRa.
7. Monitoring center receives updates.

### Women's Safety SOS Operation

1. User presses SOS button.
2. ESP32 generates emergency alert.
3. Alert is transmitted via LoRa.
4. Monitoring center receives notification.
5. Nearby street lights can activate emergency signaling.
6. Authorities/security personnel can respond quickly.

---

## 📊 Applications

### Smart City Infrastructure

* Municipal street lighting
* Urban development projects
* Smart city deployments

### Public Safety

* Women's safety systems
* Emergency alert networks
* Community protection initiatives

### Industrial & Institutional Use

* Industrial campuses
* Educational institutions
* Residential townships
* Corporate parks

### Rural Development

* Village road lighting
* Highway safety systems
* Remote area monitoring

---

## 🎯 Objectives

* Improve energy efficiency
* Enable real-time infrastructure monitoring
* Reduce maintenance costs
* Detect faults automatically
* Enhance public safety
* Support women's safety initiatives
* Create scalable smart-city infrastructure
* Enable AI-based decision making

---

## 📈 Benefits

* Reduced energy wastage
* Faster fault detection
* Lower maintenance effort
* Improved operational efficiency
* Enhanced public safety
* Reliable long-range communication
* Scalable architecture
* Future-ready smart infrastructure

---

## 🔮 Future Enhancements

### AI & Analytics

* Predictive maintenance
* Failure forecasting
* Energy consumption optimization

### Connectivity

* Cloud integration
* MQTT support
* Mobile application

### Safety Enhancements

* GPS-based emergency tracking
* SMS notifications
* Emergency service integration
* Voice-enabled SOS system

### Smart City Expansion

* Air quality monitoring
* Traffic monitoring
* Environmental sensing
* Smart utility management

---

## 📸 Project Images

Add project images inside an `/images` folder.

Recommended images:

* System Block Diagram
* Circuit Diagram
* Hardware Prototype
* LoRa Communication Setup
* Monitoring Dashboard
* SOS System Demonstration

Example:

```text
/images/block_diagram.png
/images/circuit_diagram.png
/images/hardware_setup.jpg
/images/sos_demo.jpg
```

---

## 🤝 Contributors

Contributions, ideas, suggestions, and improvements are welcome.

Feel free to:

* Fork the repository
* Create feature branches
* Submit pull requests
* Report issues

---

## 📜 License

This project is licensed under the MIT License.

See the LICENSE file for details.

---

## 🙌 Acknowledgments

Special thanks to everyone who contributed ideas, testing, development, and support throughout the project journey.

---

### ⚡ GlowGrid-AI

#### Lighting Smarter Cities. Empowering Safer Communities.
