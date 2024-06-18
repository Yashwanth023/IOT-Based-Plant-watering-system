# IoT-Based Plant Watering System

## Project Description

This project is an IoT-based automated plant watering system designed to monitor and manage the irrigation of plants efficiently. It uses various sensors to measure soil moisture, temperature, and humidity, and controls a water pump to provide water when necessary. The system is integrated with Telegram to send real-time notifications to the user's smartphone, allowing remote monitoring and manual control of the watering process.

## Features

- **Automated Watering**: Automatically waters the plants when the soil moisture level falls below a predefined threshold.
- **Real-time Monitoring**: Continuously monitors soil moisture, temperature, and humidity.
- **Remote Control**: Users can manually control the water pump via Telegram commands.
- **Notifications**: Sends notifications to the user's smartphone when the water pump is activated or deactivated.
- **LCD Display**: Displays the current soil moisture, temperature, and humidity levels on an LCD screen.

## Technologies Used

- **Microcontroller**: ESP8266-based NodeMCU for processing and connectivity.
- **Sensors**: DHT11 for temperature and humidity, soil moisture sensor for soil moisture content.
- **Actuators**: Relay module and water pump for irrigation control.
- **Programming Language**: C++ for microcontroller programming.
- **Development Environment**: Arduino IDE for code development and uploading.
- **Communication**: Wi-Fi module integrated with ESP8266 for internet connectivity.
- **Telegram Bot**: Universal Telegram Bot library for integrating Telegram messaging.

## Telegram Bot Integration

The project uses a Telegram bot to facilitate remote monitoring and control of the plant watering system. Here’s how the integration works:

1. **Bot Creation**: A Telegram bot is created and configured with a unique bot token.
2. **User Commands**: The bot is programmed to handle user commands such as `/start`, `/stop`, `/status`, and `/help`.
3. **Sensor Data**: The microcontroller reads data from the soil moisture sensor and DHT11 sensor, and sends updates to the user through the Telegram bot.
4. **Manual Control**: Users can send commands to the bot to manually start or stop the water pump.
5. **Notifications**: The bot sends notifications to the user when the water pump is turned on or off, providing updates on the system’s status.

## System Implementation

The implementation involves the following steps:

1. **Hardware Setup**: Configure the ESP8266-based NodeMCU microcontroller, connect the DHT11 sensor, soil moisture sensor, relay module, water pump, and LCD display.
2. **Software Development**: Write and upload the code using the Arduino IDE. The code handles sensor data acquisition, decision-making for watering, and communication with the Telegram bot.
3. **Telegram Bot Integration**: Use the Universal Telegram Bot library to connect the system to the Telegram API, allowing for real-time notifications and remote control.
4. **Deployment**: Deploy the system in the desired location, ensuring proper sensor placement for accurate monitoring.
5. **Operation**: Monitor the system via Telegram, where users receive notifications and can manually control the watering process.

## Conclusion

The IoT-based plant watering system effectively automates the irrigation process, ensuring optimal watering based on real-time soil moisture levels. The integration with Telegram provides a convenient way for users to monitor and control the system remotely, enhancing user experience and plant care management.

## Screen shots
1. Circuit diagram

     ![Screenshot (23)](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/47d51945-323b-48dd-b067-0271ddc87959)

2. Results

   ![WhatsApp Image 2024-05-13 at 8 49 51 AM](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/5dd3ca41-dad6-4f9e-81c5-0af9ec632d15)

   ![WhatsApp Image 2024-05-13 at 8 49 51 AM (1)](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/f06d4277-ad20-46cd-ac76-cdb0a651119c)

   ![WhatsApp Image 2024-05-13 at 8 49 52 AM](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/486103d8-f8f5-433b-b401-fdd037f8e7e7)

   ![WhatsApp Image 2024-05-13 at 8 49 52 AM (1)](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/51d6987a-a88d-4d34-9e99-6a2e38ccd3b8)

   ![WhatsApp Image 2024-05-13 at 8 49 52 AM (2)](https://github.com/Yashwanth023/IOT-Based-Plant-watering-system/assets/143989092/e84b2ab4-7683-411d-b58b-a5d9609bdef3)
