# 🚒 Autonomous Fire Fighting Car

> A Bluetooth-controlled robotic vehicle equipped with dual flame sensors and an automatic water pump — designed to detect and extinguish fires remotely, reducing the risk to human firefighters.

![Project Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20Arduino-orange)
![Team](https://img.shields.io/badge/Team-3%20Members-lightgrey)

---

## 📸 Demo

> <img width="4096" height="3072" alt="1686114170806" src="https://github.com/user-attachments/assets/6502b305-ab17-4464-9a9c-b5719f7fbc06" />
<img width="1230" height="840" alt="Screenshot 2026-07-01 040706" src="https://github.com/user-attachments/assets/9ebc395b-10ff-44f5-8101-faf1e0dbbc9b" />


---

## 📋 Table of Contents

- [The Problem](#-the-problem)
- [Our Solution](#-our-solution)
- [Features](#-features)
- [Hardware Components](#-hardware-components)
- [System Architecture](#-system-architecture)
- [Engineering & Dynamics](#-engineering--dynamics)
- [Getting Started](#-getting-started)
- [How to Use](#-how-to-use)
- [Team & Contributions](#-team--contributions)
- [Real-World Context](#-real-world-context)
- [Future Improvements](#-future-improvements)

---

## 🔥 The Problem

Firefighting is one of the most dangerous professions in the world. Firefighters face:

- **Burns and smoke inhalation** from direct fire exposure
- **Structural collapse** injuries from entering burning buildings
- **Long-term health damage** including asthma, heart disease, cancer, and lung damage
- **Death** — the NFPA recorded 62 firefighter fatalities and over 18,000 injuries in 2019 alone

Beyond individual risk, fires cause massive destruction globally:

| Risk Type | Description |
|-----------|-------------|
| Personal | Direct injury, burns, toxic gas exposure |
| Structural | Destruction of facilities and properties |
| Environmental | Spread to adjacent buildings, wildfire propagation |

Climate change is worsening the crisis — 90% of the world's regions now experience more intense heat waves, contributing to larger and more frequent wildfires. In 2020 alone, Arizona saw **2,520 wildfires** burning nearly **1 million acres**.

---

## 💡 Our Solution

We built a **remotely operated fire-fighting car** that:

- Navigates toward a fire using **Bluetooth remote control**
- **Automatically detects flames** using dual infrared flame sensors (wavelength: 760nm – 1100nm)
- **Triggers a water pump** to extinguish the fire the moment a flame is detected — no human intervention needed at the danger zone

This keeps firefighters at a safe distance while the car handles the front line.

---

## ✨ Features

- 🎮 **Bluetooth remote control** via mobile app (HC-05 module)
- 🔥 **Dual flame sensor auto-detection** (IR, 760nm–1100nm range)
- 💧 **Automatic water pump activation** on flame detection
- 🔁 **Servo-controlled nozzle** for directional water spraying
- 🚗 **4-wheel drive** with independent motor control via L298N driver
- 📡 **Wireless operation** — no physical connection needed

---

## 🔧 Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno | 1 | Main microcontroller |
| L298N Motor Driver | 1 | Controls DC motors |
| DC Motors | 4 | 4-wheel drive movement |
| Flame Sensor (IR) | 2 | Fire detection |
| Servo Motor | 1 | Nozzle direction control |
| Mini Water Pump | 1 | Water discharge |
| HC-05 Bluetooth Module | 1 | Wireless control |
| 9V Battery | 1 | Power supply |
| Jumper Wires | — | Circuit connections |

---

## 🏗️ System Architecture

```
[Bluetooth App]
      |
      ▼
[HC-05 Module] ──────► [Arduino Uno] ◄──── [Flame Sensor x2]
                              |
              ┌───────────────┼───────────────┐
              ▼               ▼               ▼
        [L298N Driver]   [Servo Motor]   [Water Pump]
              |
    ┌────┬────┬────┐
    ▼    ▼    ▼    ▼
  [M1] [M2] [M3] [M4]   ← 4 DC Motors
```

**Logic flow:**
1. User sends direction commands via Bluetooth → car moves
2. Flame sensors continuously scan the environment
3. If flame detected → servo aligns nozzle → pump activates automatically
4. Fire extinguished → pump stops

---

## 📐 Engineering & Dynamics

This project was grounded in real mechanical and electrical engineering calculations.

### 1. Angular to Linear Velocity

```
V = 2π × N × r
  = 2π × 4 rps × 0.032 m
  = 0.8042 m/s
```

### 2. Electrical to Mechanical Power Conversion

Mechanical power ≈ 90% of electrical power:

```
F × v = 0.9 × V × I
F × 0.8042 = 0.9 × 6.1V × 2.7A
F = 18.432 N

F = m × a  →  a = 18.432 / 1.232 = 14.961 m/s²
```

### 3. Kinematics

```
V = V₀ + at  →  t = 0.053 s
V² = V₀² + 2ad  →  d = 2.2 cm
```

### 4. Water Projectile Speed

```
Δy = -0.15 m  →  t = 0.175 s
Vx = Δx / t = 0.16 / 0.175 = 0.914 m/s
Vt = √(Vx² + Vy²) = 0.914 m/s
```

These calculations validated that the pump delivers water at sufficient velocity and the motors provide enough force to move the vehicle under load.

---

## 🚀 Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) installed
- Arduino Uno board + USB cable
- All hardware components assembled per the circuit diagram

### Upload the Code

1. Clone this repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/fire-fighting-car.git
   ```
2. Open the `.ino` file in Arduino IDE
3. Select **Board:** Arduino Uno and the correct **Port**
4. Click **Upload**

### Bluetooth Setup

1. Pair your phone with the **HC-05** module (default PIN: `1234`)
2. Use any Bluetooth Serial app (e.g., "Bluetooth RC Controller" on Android)
3. Configure controls: `F` = Forward, `B` = Backward, `L` = Left, `R` = Right, `S` = Stop

---

## 📱 How to Use

1. Power on the car (9V battery)
2. Connect your phone to the HC-05 via Bluetooth
3. Drive the car toward the fire zone using the app
4. The flame sensors will **automatically detect fire** and trigger the pump
5. No manual pump control needed — the car handles it

---

## 👥 Team & Contributions

| Member | Role |
|--------|------|
| **Mohamed Baleegh** | **Arduino programming, circuit logic, flame sensor integration, dynamics & kinematics calculations** |
| Omar Mohamed Saidan | Hardware assembly, component wiring |
| Omar Ahmed Sayed Ali 3 | Documentation, research, testing |

> **Mohamed** led the core technical implementation — writing all the embedded C++ code for motor control, Bluetooth communication, and the autonomous flame-detection/pump-activation logic, as well as performing all the engineering dynamics calculations that validated the vehicle's performance.

---

## 🌍 Real-World Context

This project was directly inspired by real incidents:

- **2020 Arizona wildfire season:** 2,520 fires, ~1 million acres burned, 20 buildings destroyed
- **Sicily, 2021:** Temperature reached 48.8°C — a European record — contributing to massive wildfires
- **NFPA Data:** 62 firefighter deaths and 18,000+ injuries in a single year (2019)

Robotic firefighting vehicles are already being explored by fire departments globally. Our car demonstrates the core concept at a prototype scale — autonomous detection + remote navigation + automatic suppression.

---

## 🔮 Future Improvements

- [ ] Add **temperature sensor (DHT11)** for ambient heat monitoring
- [ ] Integrate **LIDAR or ultrasonic sensors** for autonomous navigation
- [ ] Replace Bluetooth with **Wi-Fi / ESP8266** for longer range
- [ ] Add **live video feed** via camera module
- [ ] Implement **autonomous pathfinding** toward fire source
- [ ] Upgrade water reservoir capacity

---



---

<p align="center">Built as part of an Electronics & Communications Engineering university project</p>
