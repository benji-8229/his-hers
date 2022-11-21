#include "wifi_setup.h"
#include "message_handler.h"

bool portalMode = true;
int currentState = 1;
int lastState = 1; //defaults to high value because 0 means the button is pressed
uint8_t LEDpin = D1;
uint8_t BUTTONpin = D2;

void ICACHE_RAM_ATTR ISR() { //callback for when button is pressed
  if(mqtt_received() == true) {
    mqtt_set_received(false);
  }
  else {
    mqtt_send(); 
  }
}

void setup() {
  pinMode(BUTTONpin, INPUT_PULLUP);
  wifi_init(); //try and connect to wifi; wait and if we're unconnected open the setup portal

  for (int i = 0; i <= 30; i++) { //this lets us wait just as long as we need to, rather than a full 30 seconds
    if (WiFi.status() == WL_CONNECTED) {
      portalMode = false;
      break;
    }
    else {
      delay(1000);
    }
  }

  //if we didn't make a connection or we boot into setup mode turn on the onboard led and open the portal. otherwise, connect to the mqtt server
  if (portalMode or digitalRead(BUTTONpin) == LOW) {
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    portal_init();
    portalMode = true;
  }
  else {
    mqtt_connect();
    attachInterrupt(digitalPinToInterrupt(BUTTONpin), ISR, FALLING); //attach the callback for our button
  }
}

void loop() {
  if (portalMode == false) {
    mqtt_loop(); //recieve and publish any messages we need to

    if (mqtt_received() == true) {
      for (int i = 0; i < 255; i++) {
        if (!mqtt_received()) break; //we have to check in here too because if we don't the led will continue looping even while the button is pressed
        analogWrite(LEDpin, i);
      }
      for (int i = 255; i > 0; i--) {
        if (!mqtt_received()) break;
        analogWrite(LEDpin, i);
      }
    } 
    else {
      analogWrite(LEDpin, 0);
    }
  }
  else { //handle_client calls the functions for handling the AP and DNS server when in setup mode
    handle_client();
  }
}
