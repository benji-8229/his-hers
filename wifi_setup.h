#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <DNSServer.h>

void portal_init();
void handle_portal();
void wifi_init();
void handle_client();

#endif
