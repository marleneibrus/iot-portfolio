#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include <math.h>

// --- WiFi + MQTT ---
const char* ssid = "firstAID14";
const char* password = "iotempire";
const char* mqtt_server = "192.168.14.1";

// --- Hardware ---
const int ledPin = D5; // PWM-capable pin on Wemos D1 Mini
bool flashing = false;
unsigned long startTime = 0;

// --- Clients ---
WiFiClient espClient;
PubSubClient client(espClient);

// --- Setup ---
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0); // Ensure LED is off

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  ArduinoOTA.begin();
}

// --- WiFi connect ---
void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

// --- MQTT Callback ---
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == "alarm") {
    if (message == "on") {
      flashing = true;
      startTime = millis();
    } else if (message == "off") {
      flashing = false;
      analogWrite(ledPin, 0); // Turn off LED
    }
  }
}

// --- MQTT Reconnect ---
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("WemosClient")) {
      client.subscribe("alarm");
      Serial.println("connected");
    } else {
      delay(5000);
    }
  }
}

// --- Main Loop ---
void loop() {
  ArduinoOTA.handle();

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  add_to_loop();
}

// --- LED Logic ---
void add_to_loop() {
  if (flashing) {
    unsigned long currentTime = millis();
    if (currentTime - startTime < 30000) { // 30 seconds
      float t = (currentTime - startTime) / 1000.0; // Time in seconds
      int brightness = int((sin(t * PI) * 127.5) + 127.5);
      analogWrite(ledPin, brightness);
    } else {
      flashing = false;
      analogWrite(ledPin, 0); // Turn off LED
    }
  }
}
