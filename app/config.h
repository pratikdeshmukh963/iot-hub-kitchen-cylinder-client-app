// Physical device information for board and sensor
#define DEVICE_ID "ESP8266 kitchen cylinder weighing scale"
#define DHT_TYPE DHT22

// Pin layout configuration
#define LOADCELL_DOUT_PIN 0
#define LOADCELL_SCK_PIN 2

// This is actually 15.9Kg when empty for HP gas but we have other weights as gas knob and pipe
#define WEIGHT_ALERT 16500

// Interval time(ms) for sending message to IoT Hub
#define INTERVAL 2000

// If don't have a physical DHT sensor, can send simulated data to IoT hub
#define SIMULATED_DATA true

// EEPROM address configuration
#define EEPROM_SIZE 512

// SSID and SSID password's length should < 32 bytes
// http://serverfault.com/a/45509
#define SSID_LEN 32
#define PASS_LEN 32
#define CONNECTION_STRING_LEN 256

#define MESSAGE_MAX_LEN 256
