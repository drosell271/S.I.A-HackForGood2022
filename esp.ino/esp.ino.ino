/*
 * esp8266 simple WebSocket client
 * https://www.mischainti.org
 *
 * I use the ws://echo.websocket.org/ echo server
 * When you send a message to this server you receive
 * a response with the same message
 *
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

#define CLIENT 1
#define SERVER 2

SoftwareSerial esp(4, 5);

WebSocketsClient webSocket;

const char *ssid = "Eventos";
const char *password = "42Madrid";

unsigned int messageInterval = 5000;
bool connected = false;

class IOTClient {
public:
  IOTClient() {
    this->mode = -1;
  };
  IOTClient(IOTClient &);
  void operator=(IOTClient &);
  void waitMode() {
    String read;
    while (read = esp.readString()) {
      read.trim();
      if (read == "OK") {
        Serial.print("OK Received to esp");
        break;
      }
      if (read.startsWith("SET MODE")) {
        if (read.endsWith(" CLIENT")) {
          this->mode = CLIENT;
        }
        if (read.endsWith(" SERVER")) {
          this->mode = SERVER;
        }
        if (this->mode == CLIENT || this->mode == SERVER) {
          esp.println("OK");
          Serial.printf("set %d mode\n", this->mode);
          break;
        }
      }
      delay(1000);
    }
  };
  void sendMessage() {
    Serial.printf("sendMessage %d\n", this->mode);
    switch (this->mode) {
      case CLIENT:
        clientMessage();
        break;
      case SERVER:
        serverMessage();
        break;
      default:
        Serial.printf("MODE OPTIONS CLIENT SERVER");
        break;
    }
  };
  void setMode(uint8_t mode) {
    this->mode = mode;
  };
  uint8_t getMode() {
    return this->mode;
  };
private:
  uint8_t mode;
  void clientMessage() {
    webSocket.sendTXT(esp.readString().c_str());
  };
  void serverMessage() {
    String message;
    message = esp.readString();
    Serial.print(message);
    webSocket.sendTXT(message.c_str());
  };
public:
  IOTClient(IOTClient const &) = delete;
  void operator=(IOTClient const &) = delete;
};

IOTClient iotClient;

#define DEBUG_SERIAL Serial

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {
  // Serial.printf("type: %d, wse\n", type);
  // switch(type) {
  //     case WStype_DISCONNECTED:
  //         connected = false;
  //         break;
  //     case WStype_CONNECTED: {
  //         connected = true;
  //         webSocket.sendTXT("Connected");
  //     }
  //         break;
  //     case WStype_TEXT:
  //         esp.printf("%s\n", payload);
  //         break;
  // }
}

void setup() {
  Serial.begin(115200);
  esp.begin(9600);
  ESP.wdtDisable();
  ESP.wdtEnable(0);
  //  DEBUG_SERIAL.setDebugOutput(true);

  for (uint8_t t = 4; t > 0; t--) {
    DEBUG_SERIAL.flush();
    delay(1000);
  }

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  // server address, port and URL
  webSocket.begin("madornapi.local", 8080, "/");

  iotClient.waitMode();

  // event handler
  try {
    webSocket.onEvent(&webSocketEvent);
  } catch (std::exception e) {
    Serial.printf("except %s\n", e.what());
  }
}

unsigned long lastUpdate = millis();

void loop() {
  Serial.printf("connected: %s\n", connected);
  if (WiFi.status() != WL_CONNECTED) {
    webSocket.disconnect();
  } else {
    // if (lastUpdate + messageInterval < millis()) {
      webSocket.loop();
      iotClient.sendMessage();
      lastUpdate = millis();
    // }
  }
}