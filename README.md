# Temperature-Humidity-Monitoring

# ESP32 Temperature and Humidity Monitoring System with SD Card Data Logging

![ESP32](https://img.shields.io/badge/Microcontroller-ESP32-blue)
![Sensor](https://img.shields.io/badge/Sensor-DHT11-green)
![Arduino IDE](https://img.shields.io/badge/Platform-ArduinoIDE-orange)
![Embedded Systems](https://img.shields.io/badge/Domain-EmbeddedSystems-red)
![IoT](https://img.shields.io/badge/Application-IoT-purple)

---

# Project Overview

This project presents a real-time **Temperature and Humidity Monitoring System** developed using the **ESP32 microcontroller**, **DHT11 sensor**, **16×2 LCD display**, and **SD card module**.

The system continuously measures environmental conditions and performs three major operations simultaneously:

- Real-time temperature sensing
- Real-time humidity sensing
- Data logging into an SD card for future analysis

The measured values are displayed live on a 16×2 LCD screen while also being stored in CSV/text format on a micro SD card at regular intervals.

The project demonstrates the integration of:
- sensor interfacing
- embedded programming
- SPI communication
- I2C communication
- real-time monitoring
- data acquisition and logging

The complete system was implemented using the **ESP32 microcontroller platform** and programmed in the **Arduino IDE**.

---

# Objective

The primary objective of this project is to design a low-cost and efficient environmental monitoring system capable of:

- measuring temperature
- measuring humidity
- displaying data in real time
- storing environmental data for historical analysis
- enabling future IoT-based remote monitoring applications

---

# Features

- Real-time temperature monitoring
- Real-time humidity monitoring
- LCD display output
- SD card data logging
- CSV/text format storage
- Timestamp generation using ESP32 runtime
- Continuous environmental monitoring
- Compact and cost-effective design
- Simple embedded system architecture
- Expandable for IoT applications

---

# System Architecture

```text
DHT11 Sensor
      ↓
ESP32 Microcontroller
      ↓
 ┌───────────────┬───────────────┐
 ↓               ↓
16×2 LCD      SD Card Module
Display       Data Logging
```

The DHT11 sensor continuously measures environmental parameters and sends the data to the ESP32 through GPIO communication.

The ESP32:
- processes the sensor readings
- displays values on LCD
- generates timestamps
- stores readings into SD card files

The LCD provides real-time monitoring while the SD card module enables long-term storage and analysis.

---

# Hardware Components Used

| Component | Description |
|---|---|
| ESP32 Microcontroller | Main controller for processing and communication |
| DHT11 Sensor | Measures temperature and humidity |
| 16×2 LCD with I2C Module | Displays sensor values in real time |
| SD Card Module | Stores sensor data into memory card |
| Micro SD Card | Data storage medium |
| Breadboard & Jumper Wires | Circuit connections |
| Power Supply | Provides regulated voltage |

---

# Why ESP32 Was Used

The ESP32 microcontroller was selected because it provides:

- high processing capability
- multiple GPIO pins
- built-in Wi-Fi and Bluetooth
- SPI communication support
- I2C communication support
- low power operation
- easy integration with sensors and modules

ESP32 acts as the central controller of the entire system.

---

# Why DHT11 Sensor Was Used

The DHT11 sensor is a low-cost digital sensor capable of measuring:

- temperature
- humidity

Advantages:
- easy interfacing
- digital output
- stable performance
- low cost
- suitable for basic environmental monitoring

---

# Working Principle

The system operates continuously in a loop.

## Step 1 — Sensor Initialization

The ESP32 initializes:
- DHT11 sensor
- LCD display
- SD card module

---

## Step 2 — Temperature and Humidity Sensing

The DHT11 sensor measures:
- ambient temperature
- relative humidity

The sensed values are transmitted to the ESP32.

---

## Step 3 — Data Processing

The ESP32 processes:
- temperature values
- humidity values
- timestamps

Invalid readings are filtered out.

---

## Step 4 — LCD Display

The processed values are displayed on the LCD screen in real time.

Example:

```text
T:31.4°C
00:00:26
```

---

## Step 5 — Timestamp Generation

The ESP32 generates timestamps using the internal runtime counter (`millis()`).

The format used is:

```text
HH:MM:SS
```

---

## Step 6 — SD Card Data Logging

The sensor data is stored into a file on the SD card.

Logged parameters:
- timestamp
- temperature
- humidity

Data is stored in CSV/text format for easy analysis.

Example:

```text
Time,Temp(C),Humidity(%)
00:00:03,30.50,65.00
00:00:05,30.40,65.00
```

---

# Software Used

| Software | Purpose |
|---|---|
| Arduino IDE | Programming ESP32 |
| ESP32 Board Package | ESP32 support |
| Serial Monitor | Debugging |
| SD Library | SD card interfacing |
| SPI Library | SPI communication |
| Wire Library | I2C communication |

---

# Libraries Used

```cpp
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>
```

---

# Pin Configuration

| Component | ESP32 Pin |
|---|---|
| DHT11 Data Pin | GPIO 4 |
| SD Card CS Pin | GPIO 5 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

---

# Program Workflow

## System Start

- Initialize ESP32
- Initialize DHT11
- Initialize LCD
- Initialize SD card

---

## SD Card Verification

The system checks whether the SD card is detected.

If initialization fails:
- error message displayed on LCD

Otherwise:
- system proceeds normally

---

## Continuous Monitoring Loop

The system continuously:
1. reads temperature
2. reads humidity
3. validates sensor data
4. updates LCD display
5. generates timestamp
6. stores readings in SD card
7. waits 2 seconds
8. repeats process

---

# Code Explanation

## Sensor Reading

```cpp
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();
```

Reads humidity and temperature from DHT11.

---

## Data Validation

```cpp
if (isnan(humidity) || isnan(temperature))
```

Checks for invalid sensor readings.

---

## LCD Display

```cpp
lcd.print(temperature);
```

Displays live temperature values.

---

## Timestamp Generation

```cpp
unsigned long totalSeconds = millis() / 1000;
```

Converts runtime into seconds.

---

## SD Card Logging

```cpp
dataFile = SD.open("/data.txt", FILE_APPEND);
```

Appends sensor data into storage file.

---

# Data Logging Format

The stored data format:

```text
Time,Temp(C),Humidity(%)
00:00:03,30.50,65.00
00:00:05,30.40,65.00
```

Advantages:
- easy analysis
- CSV-compatible
- lightweight storage
- readable format

---

# Hardware Setup

## Hardware Components

- ESP32 development board
- DHT11 sensor
- 16×2 LCD with I2C module
- SD card module
- Breadboard
- jumper wires

---

# Communication Protocols Used

## I2C Communication

Used for:
- LCD interfacing

Advantages:
- reduced wiring
- fewer GPIO pins

---

## SPI Communication

Used for:
- SD card module

Advantages:
- fast communication
- reliable data transfer

---

# Results

The system successfully:
- measured environmental conditions
- displayed real-time data
- stored readings into SD card

Observed outputs:
- stable sensor readings
- successful SD card logging
- continuous monitoring operation

---

# Applications

This system can be used in:

- Agriculture monitoring
- Greenhouse monitoring
- Industrial monitoring
- Environmental monitoring
- Smart homes
- Storage rooms
- Healthcare environments
- Weather stations
- Laboratory monitoring

---

# Advantages

- Low cost
- Easy implementation
- Compact design
- Real-time monitoring
- Expandable architecture
- Reliable logging system
- Low power consumption
- Portable solution

---

# Limitations

- DHT11 has limited accuracy
- No internet connectivity
- Local storage only
- Basic timestamp generation
- No cloud integration

---

# Future Improvements

Future enhancements may include:

- IoT cloud integration
- Wi-Fi dashboard
- Mobile app monitoring
- Blynk integration
- Firebase cloud logging
- Email/SMS alerts
- Real-time web server
- MQTT communication
- Temperature threshold alarms
- Automated cooling system
- More accurate sensors (DHT22/BME280)

---
