#include "message_handler.h"

bool received = false;
const char* mqtt_server = "broker.emqx.io";
const char* mqtt_user = "hisClient"; //we dont actually need a username because we use an unauthenticated and public broker, we can just use it as a clientID
WiFiClient wifiClient;
PubSubClient client(mqtt_server, (int)1883, callback, wifiClient);


void mqtt_connect() {
  while (!client.connected()) {
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);

    if (!client.connect(mqtt_user)) {
      delay(5000);
    } 
    else {
      pinMode(2, OUTPUT);
      digitalWrite(2, HIGH);
    }
  }
  client.subscribe("hishers/signals", 1);
}

void mqtt_loop() {
  if (!client.connected()) {
    mqtt_connect();
  }
  client.loop();
}

bool mqtt_send() {
  if (!client.connected()) {
    mqtt_connect();
  }
  received = false;
  return client.publish("hishers/signals", mqtt_user, 2);
}

void mqtt_set_received(bool tf) {
  received = tf;
}

bool mqtt_received() { 
  return received;
}

void callback(char* topic, byte* payload, unsigned int length) {
  char payloadChars[length+1];
  
  for (int i = 0; i < length; i++) {
    payloadChars[i] = (char)payload[i];
  }
  payloadChars[length] = '\0';

  //all payloads sent are just mqtt_user, so if the payload is different than our mqtt_user it came from a different board
  if (strcmp(payloadChars, mqtt_user) != 0) {
    received = true;
  }
}
