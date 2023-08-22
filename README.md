<div align="center">
<img width=200 alt="logo JS-BLE-DOC" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/0afd19ac-6f4f-4478-bcf5-080bf4258cda">

# [ :book: ESP32 Coop Door Documentation ](https://coop-door.vercel.app/) 

The goal is to document the setup & configuration of the [esp32-coop](https://github.com/ESP32-COOP) projet as well as the protocol in which the two devices communicate over BLE 
</div>


# :memo: Summary:

- :page_facing_up: **Projet Overview**: quick presentation of the mother project (goal, link device, protocol used, problematic) 
- [:iphone: **The App**: how to get the it](https://github.com/ESP32-COOP/JS-BLE-DOC#iphone-app-installation)
- :toolbox: **Build instruction**
   - :clipboard: **Requirement**: the wiring diagram
   - :rocket: First Boot
   - :house: 3D file (//todo)
- :signal_strength: **Communication protocol**
   - :electric_plug: Run-down on how BLE works 
   - :bar_chart: The type of data required by the project (in progress) 
   - :computer: Code snippet for each characteristic (in progress)


# :page_facing_up: Project Overview

The [COOP-DOOR](https://github.com/ESP32-COOP) project aims to create an intelligent and user-friendly automatic coop door system. It empowers users to customize the door's behavior based on specific conditions, such as time and light levels. To facilitate device management and monitoring, the project offers a mobile app. The app enables users to track device and sensor health, as well as configure various operating conditions. For a demonstration of the project, please refer to the demo [here](https://github.com/ESP32-COOP/ESP32-COOP-DOOR-WEB). The core of the smart coop door relies on the ESP-32 platform, and the code repository can be found [here](https://github.com/ESP32-COOP/ESP32-COOP-DOOR-CORE). This documentation page aims to guide users through the setup process, hardware requirements, and detailed workings of the system.

# :iphone: App Installation


<img width=100 alt="app icon" align="left" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/8056a93b-1d68-41e8-b1e9-84ded7e0bde6">
<br clear="right"/>
The coop door application is a Progressive Web App, meaning it functions as a website and can be installed on mobile devices for offline usage.
<br clear="left"/>
<br clear="left"/>

To install the app, follow these steps:

1. Visit [coop-door.vercel.app](https://coop-door.vercel.app) using your mobile device's web browser.
2. A small popup will prompt you to install the app. Tap "Install" to proceed.
3. Alternatively, if the popup doesn't appear, you can manually add the app to your home screen by:
   - Tapping the three dots in Chrome.
   - Scrolling down and selecting "Add shortcut to home screen" or "Install app."
4. The app will be installed on your device and accessible from the home screen.

Now, you can conveniently use the mobile app to monitor and control your coop door system, even without an internet connection.

# :electric_plug: BLE Protocol

<img width=100 alt="BLE illustration" align="left" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/77d5236b-3843-43ea-ab0d-cbb7d245f219">
<br clear="right"/>
To better understand the following, you must understand the basics of the Bluetooth Low Energy (BLE) protocol.<br/>
The key part to understand is that it uses a fixed-size array of bytes to send data to an endpoint.
<br clear="left"/>
<br clear="left"/>



Each endpoint can have three properties: writable, readable, and notifyable.

- Writable: It allows the external user to write/edit the endpoint (officially called characteristic in BLE).
- Readable: It allows reading the characteristic's value.
- Notifyable: It allows getting notified when that value is updated.

A byte is made out of 8 bits, and its value can go from 0 to 255.

To send the desired value in bytes, you must think it through:

- You will need to figure out the array size you will need and the function to convert it back and forth in C and in JS.

Currently, there are five communication subjects:
1. The light sensor (made out of 4 bytes).
2. The time (made out of 9 bytes, 8 to represent UNIX time and 1 to represent the UTC offset).


# Requirement


This projet use a ESP32 WEMOS lolin32 lite, a H-Bridge l298n, a motor with a encoder, a final a photoresistor
#### Illustration:
<img width="1588" alt="wiring diagram" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/fa3992ba-100c-4e66-be85-4387ff7f884b">



### :bulb: Idea:
#### Light Data
```c++
int analogValue = analogRead(A0); // Read the analog value from the light resistor or ble_value = random(10, 10000);
//int analogValue = random(10, 10000);
int minValue = 100; // Replace with your own minimum value
int maxValue = 800; // Replace with your own maximum value

// Calculate the divider to scale the values to fit in a byte
float divider = maxValue / 255.0;

// Scale the current value, min value, and max value to fit in a byte
uint8_t currentValue = analogValue / divider;
uint8_t scaledMinValue = minValue / divider;
uint8_t scaledMaxValue = maxValue / divider;

// Create an array to store the scaled values
uint8_t ble_value_array[4] = {currentValue, scaledMinValue, scaledMaxValue, (uint8_t)divider};

// Write the array to the characteristic
switchCharacteristic2.writeValue(ble_value_array, 4);
```

![Communication between JS and an ESP32](https://github.com/ESP32-COOP/JS-BLE-LIB/assets/37497007/fc5af1d0-81f3-4928-ad49-e429e57f3b67)
