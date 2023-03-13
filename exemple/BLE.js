let id;
let bluetoothDeviceDetected;
let service;
let GATT_date;


let dateService = '1ce76320-2d32-41af-b4c4-46836ea7a62a'.toLowerCase();
let dateChar = 'ad804469-19ec-406a-b949-31ae17e43813'.toLowerCase();

const deviceName = 'COOP-DOOR';


function iSWebBLEAvailable() {
		if (!navigator.bluetooth){
		console.log('not available');
		return false;
		}
		return true;
		
	}
function getDeviceInfo() {
		let options = {
			//acceptAllDevices: true,
			optionalServices : [dateService, dateChar ],
			filters : [
			{namePrefix: deviceName}
			]
		}

		console.log("Requestion BLE device info...")
		return navigator.bluetooth.requestDevice(options).then(device => {
			bluetoothDeviceDetected = device;
			console.log('name '+device.name);
		}).catch(error => {
			console.log('Request device error: '+error);
		})
	}

async function connectGATT(){

  	deviceConnected = await bluetoothDeviceDetected.gatt.connected;
  	server = await bluetoothDeviceDetected.gatt.connect()

  	service2 = await server.getPrimaryService(dateService);
  	GATT_date = await service2.getCharacteristic(dateChar);

  }
async function readChar(char) {
		const dump = await char.readValue()
		return dump
}

async function readDate() {
		const dump = await readChar(GATT_date)
		console.log(dump)
		return getLongFromBytesBuffer(dump)
}

 function writeDate(){

	  let now =  Math.round(Date.now() / 1000); //Date.now();
	  let bytes = getBytesFromLong(now);
	  console.log(now,bytes,getLongFromBytes(bytes))
	  let buffer = new Uint8Array(bytes).buffer;
	  GATT_date.writeValue(buffer);
	}

function getBytesFromLong(x) {
	  let bytes = new Array(8);
	  for (let i = 0; i < 8; i++) {
	    bytes[i] = x & 0xff;
	    x = (x - bytes[i]) / 256;
	  }
	  return bytes;
	}





function getLongFromBytes(bytes) {
	  let result = 0;
	  for (let i = 7; i >= 0; i--) {
	    result = (result * 256) + bytes[i];
	  }
	  return result;
	}
function getLongFromBytesBuffer(bytes) {
	  let result = 0;
	  for (let i = 7; i >= 0; i--) {
	    result = (result * 256) + bytes.getUint8(i);
	  }
	  return result;
	}

