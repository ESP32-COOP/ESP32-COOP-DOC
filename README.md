<div align="center">
<img width=200 alt="logo JS-BLE-DOC" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/0afd19ac-6f4f-4478-bcf5-080bf4258cda">

# [ :book: ESP32 Coop Door Documentation ](https://coop-door.vercel.app/) 

The goal is to document the setup & configuration of the [esp32-coop](https://github.com/ESP32-COOP) projet as well as the protocol in which the two devices communicate over BLE 
</div>


# :memo: Summary:

- [:page_facing_up: **Projet Overview**](page_facing_up-project-overview): quick presentation of the mother project (goal, link device, protocol used, problematic) 
- [:iphone: **The App**](#iphone-app-installation): how to get the it
- [:toolbox: **Build instruction**](#toolbox-build-instruction)
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


# :toolbox: Build instruction

Look out for instruction variations depending on the version of the project you're building.

First of all, you will need to flash the firmware on the ESP32. Please refer to the instructions [here](https://github.com/ESP32-COOP/ESP32-COOP-DOOR-CORE). I do recommend unplugging the motor before flashing the firmware to avoid any connection problems caused by the encoder or any accidental movement of the powered motor.

## :clipboard: Requirement


This projet use :<br>
- a ESP32 [WEMOS lolin32 lite](https://fr.aliexpress.com/item/4000038780903.html?spm=a2g0o.productlist.main.1.365b7074KBRyQT&algo_pvid=fa4a7510-076f-4fb9-8ed4-3253a3a69928&algo_exp_id=fa4a7510-076f-4fb9-8ed4-3253a3a69928-0&pdp_npi=4%40dis%21EUR%212.40%212.4%21%21%212.56%21%21%402132a21116927149487777888ec3b7%2112000030098281375%21sea%21FR%21821278985%21&curPageLogUid=oNK3v7tChtb8) ( can be any esp32 with BLE), <br>
- a H-Bridge [l298n](https://fr.aliexpress.com/item/1005004510885871.html?spm=a2g0o.productlist.main.1.4ab84eaai4P1f2&algo_pvid=83586f20-9cd5-4dc6-a3a3-c75def78a4cb&algo_exp_id=83586f20-9cd5-4dc6-a3a3-c75def78a4cb-0&pdp_npi=4%40dis%21EUR%211.74%211.53%21%21%211.85%21%21%402132a21116927149924648112ec3b7%2112000029421559001%21sea%21FR%21821278985%21&curPageLogUid=vMEusi5qQJYG),<br> 
- a [motor with a encoder](https://fr.aliexpress.com/item/4001314473291.html?spm=a2g0o.productlist.main.1.52dd699a8YKYiK&algo_pvid=2a4b28bb-bc90-458b-ae85-f85eb2cfdece&algo_exp_id=2a4b28bb-bc90-458b-ae85-f85eb2cfdece-0&pdp_npi=4%40dis%21EUR%215.76%215.76%21%21%216.14%21%21%402132a21116927150494998265ec3b7%2110000015695661379%21sea%21FR%21821278985%21&curPageLogUid=HH3ljdlfyhi0), <br>
- and a [photoresistor](Vhttps://fr.aliexpress.com/item/32760631393.html?spm=a2g0o.productlist.main.1.5dd44f76NrlFVE&algo_pvid=25a08ae4-57ee-4d4c-91c6-76967f27dc4b&algo_exp_id=25a08ae4-57ee-4d4c-91c6-76967f27dc4b-0&pdp_npi=4%40dis%21EUR%210.72%210.6%21%21%210.77%21%21%402132f35616927151872427277e2c69%2110000001115154392%21sea%21FR%21821278985%21&curPageLogUid=ZBl0dvCbwSIm)

Additionally, you'll need some basic items such as wires, soldering equipment (or soldering iron), and a 3D printer or woodworking tools, depending on your preferences.

Please note that you can easily swap out any component of this project for a similar one. It will most likely work out fine, but it may require some extra work. I would recommend it only to experienced thinkers.

## :electric_plug: Wiring
As illustrated below, follow these connections:

ESP32:
- Connect encoder signal to pin 2 (yellow) and pin 15 (green).
- Attach a resistor to pin 34 for analog value.
- Control the H-bridge with pins 27 (ENA), 26 (IN1), and 15 (IN2).

Remember to establish a ground connection between the H-bridge and the ESP32.

<img width="1588" alt="wiring diagram" src="https://github.com/ESP32-COOP/JS-BLE-DOC/assets/37497007/fa3992ba-100c-4e66-be85-4387ff7f884b">

## :rocket: Initial Setup

**Before Coop Installation:**

It's a good idea to run comprehensive tests before installing the device in the coop. Debugging is much easier and less frustrating when you're comfortably situated in a well-ventilated room.

**Initial ESP32 Boot:**

When the ESP32 boots up initially, it assumes the door is closed. If that's not the case, unplug either the motor or the ESP and manually close the door.

**Proper Device Boot:**

Now you can properly start up your device. Inside the app, go to settings and then to the door section. Set the number of rotations you want the motor to perform in order to open the door. Click the test button, and the motor will complete a full cycle (going up and then back down). Begin with a small rotation number, and gradually adjust it until you reach your desired door height.

**Optimal Rotation Value:**

Once you've figured out the best number of motor rotations, jot down this value along with the light sensor reading. To sync the ESP32's time, head to the app's home page and click on the time badge. A panel will appear, showing the time difference between your phone and the ESP32, along with a sync button.

**Setting Conditions:**

With that sorted, configure open and closing conditions in the door settings. Base these conditions solely on time, and set the door to stay open for the rest of the day.

**Chicken Entry Time:**

Return to the coop at the designated chicken entry time to check the light sensor value. If needed, adjust the closing condition within the app's settings.

**Autonomous Operation:**

To enable autonomous operation, revisit the settings and door page. Click on 'auto' and then 'apply'.

## :carpentry_saw: Casing Details

You can find the 3D model at this #link, and the technical drawing is available at this #link.


# :loudspeaker: BLE Protocol

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
