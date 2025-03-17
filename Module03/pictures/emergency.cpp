#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define BUTTON_PIN 2    // GPIO2 connected to the emergency button
#define LED_PIN 13      // Indicator LED
#define MQTT_TOPIC "emergency/call"

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";
const char* mqtt_server = "broker.mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);

int lastButtonState = HIGH;  // Stores the last button state
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE 50
char msg[MSG_BUFFER_SIZE];

void setup_wifi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "EmergencyButton-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected to MQTT!");
      client.subscribe(MQTT_TOPIC);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5s...");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button with internal pull-up
  pinMode(LED_PIN, OUTPUT);           // LED indicator
  Serial.begin(115200);
  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) { // Button pressed
    Serial.println("Emergency Button Pressed! Calling Doctors...");
    snprintf(msg, MSG_BUFFER_SIZE, "Emergency: Doctor Needed!");
    client.publish(MQTT_TOPIC, msg);
    
    digitalWrite(LED_PIN, HIGH);  // Turn on LED to show alert sent
    delay(1000);                  // Avoid multiple rapid presses
    digitalWrite(LED_PIN, LOW);
  }

  lastButtonState = buttonState;  // Update button state
}
