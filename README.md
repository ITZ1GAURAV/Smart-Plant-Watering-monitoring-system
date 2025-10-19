# Smart Plant Watering & Monitoring System

## Project Description
This project automatically waters plants when the soil is dry and monitors environmental conditions. It measures soil moisture, temperature, and humidity, displays readings on a 16x2 LCD, and connects to a mobile app (Blynk) for remote monitoring. It helps keep plants healthy while teaching IoT, coding, and automation.

## Features
- Automatic plant watering when soil is dry
- Real-time soil moisture, temperature, and humidity monitoring
- Data displayed on a 16x2 LCD
- Mobile app (Blynk) integration for remote monitoring and manual control
- Easy to expand for multiple plants or notifications

## How it Works
1. **ESP32 Microcontroller** reads data from sensors.
2. **Soil Moisture Sensor** detects dryness of the soil.
3. **DHT11/DHT22 Sensor** measures temperature and humidity.
4. **Relay Module** controls the water pump based on soil moisture.
5. **16x2 LCD** displays soil moisture, temperature, and humidity readings.
6. **Blynk App** on phone receives real-time updates and can control the pump manually.

## Parts List
See `BOM.csv` for detailed list of components, quantity, approximate cost, and notes.

## Usage
1. Upload Arduino code to ESP32.
2. Connect all sensors, relay, pump, and LCD as per the wiring plan.
3. Power up ESP32.
4. Monitor readings on the LCD and your phone app.
5. Watering happens automatically when the soil is dry.

## Learning Outcomes
- Working with microcontrollers and sensors
- Understanding IoT concepts and mobile app integration
- Controlling devices with relays
- Basic electronics and coding practice
