#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsClient.h>
#include <ArduinoJson.h>


// Wifi Credentials
const char* ssid = "NETGEAR76"; // Wifi SSID
const char* password = "elegantplanet085"; //Wi-FI Password

WebSocketsClient webSocket; // websocket client class instance

StaticJsonDocument<100> doc; // Allocate a static JSON document

void setup() {
  // Connect to local WiFi
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  const char * ip_ =  "139.155.158.174"
  Serial.print("IP Address: ");
  WiFi.setHostname(ip_)
  Serial.println(WiFi.localIP()); // Print local IP address

  //address, port, and URL path 
  webSocket.begin("192.168.1.25", 81, "/"); 
  // webSocket event handler
  webSocket.onEvent(webSocketEvent);
  // if connection failed retry every 5s
  webSocket.setReconnectInterval(5000);
}
void loop() {
  webSocket.loop(); // Keep the socket alive
}
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  // Make sure the screen is clear
  //  u8g2.clearBuffer();
  if (type == WStype_TEXT)
  {
    DeserializationError error = deserializeJson(doc, payload); // deserialize incoming Json String. Make sure to use this later for combining multiple throughputs
    if (error) { // Print erro msg if incomig String is not JSON formated
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }
    const float sound = doc["sound"]; // Float variable for the sound 
    // Print the received data for debugging and analyzing in R
    Serial.println(sound);
    // Send acknowledgement
    // webSocket.sendTXT("OK");
    /* LED: OFF
       TMP: Temperature
       Hum: Humidity
    */
  }
}