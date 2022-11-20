#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H
#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

void callback(char* topic, byte* payload, unsigned int length);
void mqtt_connect();
void mqtt_loop();
bool mqtt_send();
bool mqtt_received();

#endif
