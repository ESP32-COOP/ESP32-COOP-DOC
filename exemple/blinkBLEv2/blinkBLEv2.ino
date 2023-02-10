 #include <ArduinoBLE.h>

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service

// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
BLEByteCharacteristic switchCharacteristic2("77a57c66-3bc9-463a-bc52-1ee5763b9c0f", BLERead | BLENotify);

BLEService dateService("1ce76320-2d32-41af-b4c4-46836ea7a62a"); // Bluetooth® Low Energy LED Service
BLECharacteristic dateCharacteristic("ad804469-19ec-406a-b949-31ae17e43813", BLERead | BLENotify | BLEWrite,5);

const int ledPin = LED_BUILTIN; // pin to use for the LED
uint8_t ble_value = 0x0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("COOP-DOOR");
  BLE.setAdvertisedService(ledService);
  BLE.setAdvertisedService(dateService);

  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);
  ledService.addCharacteristic(switchCharacteristic2);
  
  dateService.addCharacteristic(dateCharacteristic);

  // add service
  BLE.addService(ledService);

  BLE.addService(dateService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);
  switchCharacteristic2.writeValue(0);

  dateCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("BLE LED Peripheral");
}

void loop() {
  // listen for Bluetooth® Low Energy peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      
      if (switchCharacteristic.written()) {
         Serial.println("update");
        if (switchCharacteristic.value()) {   // any value other than 0
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);         // will turn the LED on
        } else {                              // a 0 value
          Serial.println("LED off");
          digitalWrite(ledPin, LOW);          // will turn the LED off
        }
      }

      if (dateCharacteristic.written()){
        Serial.println("Date update");
         Serial.println(dateCharacteristic.value()[0]);
         Serial.println(dateCharacteristic.value()[1]);
         Serial.println(dateCharacteristic.value()[2]);
         Serial.println(dateCharacteristic.value()[3]);
         Serial.println(dateCharacteristic.value()[4]);
      }
        ble_value = random(0, 11);
        switchCharacteristic2.writeValue(ble_value);
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }

  
  
  
}
