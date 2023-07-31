# [ESP32-COOP-DOOR](https://coop-door.vercel.app/)
Coop Door made with a Esp32

the goal is to document to protcol in wich the 2 device comunicate

## BLE protocol

to better understand the following you must understand the basic of the Bluetooth low enrgy protocol

the key part to understand is that it uses fix size array of bytes to send data to an end point

each endpoint can have 3 propretise, writable, readble, and notifyable

like that the naming indicate, it allow the exteranl user to write/edit the end point ( it is officaly call charactertistique in BLE) read the charatersisitque and get notify when that value is updated

a bytes is made out of 8 bit, it value can go from 0 to 255, 

to unable you to send the wanted value in bytes must think it throw, 

you will need to sigure out the array size you will need and the fuction to convert it and back in C and in jS

currently there is 5 communication subjet
- the light sensor
- the time
- the closeing door condition
- the opening door condition
- the current door settings


### light sensor
make out of 4 bytes

### time
make out of 9 bytes 8 to repsrente UNIX time and 1 to rpresente the UTC offset
  

### Idea :
#### Light data
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
