
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = ""; // Enter DEVICE ID
const char SSID[]               = "";    // Enter WiFi SSID (name)
const char PASS[]               = "";    // Enter WiFi password
const char DEVICE_KEY[]         = "";    // Enter Secret device password (Secret Key)

#define wifiLed    2   // LED Pin for WiFi status
#define lampu1Pin  19   // Define pin for lampu2
#define lampu2Pin  22   // Define pin for lampu2
#define lampu3Pin  23   // Define pin for lampu3

CloudSwitch lampu1;
CloudSwitch lampu2;
CloudSwitch lampu3;

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(lampu1, READWRITE, ON_CHANGE, onLampu1Change);
  ArduinoCloud.addProperty(lampu2, READWRITE, ON_CHANGE, onLampu2Change);
  ArduinoCloud.addProperty(lampu3, READWRITE, ON_CHANGE, onLampu3Change);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

void doThisOnConnect() {
  Serial.println("Board successfully connected to Arduino IoT Cloud");
  digitalWrite(wifiLed, HIGH); // Turn on WiFi LED
}

void doThisOnSync() {
  Serial.println("Thing Properties synchronized");
}

void doThisOnDisconnect() {
  Serial.println("Board disconnected from Arduino IoT Cloud");
  digitalWrite(wifiLed, LOW); // Turn off WiFi LED
}

void setup() {
  Serial.begin(9600);
  delay(1500);
  
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::CONNECT, doThisOnConnect);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, doThisOnSync);
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::DISCONNECT, doThisOnDisconnect);
  
  pinMode(wifiLed, OUTPUT);
  pinMode(lampu1Pin, OUTPUT);
  pinMode(lampu2Pin, OUTPUT);
  pinMode(lampu3Pin, OUTPUT);
  
  digitalWrite(wifiLed, LOW); // Initialize WiFi LED to OFF
  digitalWrite(lampu1Pin, LOW); // Initialize lampu2 to OFF
  digitalWrite(lampu2Pin, LOW); // Initialize lampu2 to OFF
  digitalWrite(lampu3Pin, LOW); // Initialize lampu3 to OFF
}

void loop() {
  ArduinoCloud.update();
}

void onLampu1Change() {
  digitalWrite(lampu1Pin, lampu1 ? HIGH : LOW);
  Serial.println(lampu1 ? "Lampu1 ON" : "Lampu1 OFF");
}

void onLampu2Change() {
  digitalWrite(lampu2Pin, lampu2 ? HIGH : LOW);
  Serial.println(lampu2 ? "Lampu2 ON" : "Lampu2 OFF");
}

void onLampu3Change() {
  digitalWrite(lampu3Pin, lampu3 ? HIGH : LOW);
  Serial.println(lampu3 ? "Lampu3 ON" : "Lampu3 OFF");
}
