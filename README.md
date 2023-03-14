# [ESP32-COOP-DOOR](https://coop-door.vercel.app/)
Coop Door made with a Esp32

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
