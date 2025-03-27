# Transmitter and Receiver NRF24L01 Setup

This repository contains the code and circuit setup for a wireless communication system using the NRF24L01 modules. It consists of two main components: the **transmitter** and **receiver**, both based on Arduino Nano. The transmitter is powered by a 3.7V battery, while both systems are equipped with an **AMS1117 3.3V voltage regulator**, capacitors, and NRF24L01 modules.

## Components Used:

### Transmitter:
- 1x Arduino Nano
- 1x NRF24L01 Module
- 1x AMS1117 3.3V Voltage Regulator
- 2x 10uF Capacitors
- 1x 3.7V Battery

### Receiver:
- 1x Arduino Nano
- 1x NRF24L01 Module
- 1x AMS1117 3.3V Voltage Regulator
- 2x 10uF Capacitors

## Circuit Connection Setup:

### **Transmitter Circuit:**
1. **Arduino Nano to NRF24L01:**
   - VCC to 3.3V (from AMS1117 regulator)
   - GND to GND
   - CE to D9
   - CSN to D10
   - SCK to D13
   - MOSI to D11
   - MISO to D12
   - IRQ to D2 (optional)
   
2. **AMS1117 Regulator:**
   - Input connected to 3.7V battery (ensure correct polarity)
   - Output provides 3.3V to the NRF24L01 and Arduino Nano
   
3. **Capacitors:**
   - Two 10uF capacitors placed across VCC and GND for stabilization.

### **Receiver Circuit:**
1. **Arduino Nano to NRF24L01:**
   - VCC to 3.3V (from AMS1117 regulator)
   - GND to GND
   - CE to D9
   - CSN to D10
   - SCK to D13
   - MOSI to D11
   - MISO to D12
   - IRQ to D2 (optional)

2. **AMS1117 Regulator:**
   - Input connected to your power supply
   - Output provides 3.3V to the NRF24L01 and Arduino Nano.

## Code:
Upload the corresponding transmitter and receiver code to the Arduino Nano using the Arduino IDE. The code allows the devices to communicate wirelessly via the NRF24L01 modules.

## Share Your Setup:
Feel free to share your setup on social media. Here's the [aketch setup on facebook](https://www.facebook.com/share/p/19xkkejhZH/).
