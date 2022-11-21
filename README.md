# his-hers

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)  [![benji8229](https://img.shields.io/badge/Medium-12100E?style=for-the-badge&logo=medium&logoColor=white) ](https://benji8229.medium.com/)

`his-hers` is a pair of identical IoT devices created for people in medium to long distance relationships feel more connected. 

## How it Works

When you plug one in for the first time, wait and a blue LED should light showing the board is ready to be setup. Open your WiFi settings on phone or computer and join the network `his/hers-setup`. You should be redirected to a page where you can configure the network you want the device to join. After that, simply unplug and plug it back in.

Each device has a button and a light. Push the button on your board and it will make the light on your partners board flash. They can turn off their light by pressing the button once, and send light to yours by pressing again.

![his-hers bllinking](https://i.imgur.com/eCxtpzU.gif)

## Development

This project was initially imagined and prototyped in late 2021, but school and life got in the way until now. I decided to restart and finish it now, in time to give it as a Christmas gift.

The project is running off an `ESP8266 NodeMCU`, and the boards communicate through the `MQTT messaging protocol`. The amount of data transmitted is tiny, small enough we can actually just use free MQTT brokers intended for testing. The only dependency is our Arduino MQTT client, [pubsubclient](https://github.com/knolleary/pubsubclient) by Nick O'Leary.

I would like to thank **MrDIYLab** on Instructable for his [code and instructions](https://www.instructables.com/How-to-Add-a-Setup-Portal-to-ESP8266-Projects/) posted to Instructables. HTML/CSS are not my strong suit and this helped me get started much quicker.

## Recreation
#### Material List
- [Esp8266 NodeMCU](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010N1SPRK/ref=pd_lpo_2?pd_rd_w=EwZEn&content-id=amzn1.sym.116f529c-aa4d-4763-b2b6-4d614ec7dc00&pf_rd_p=116f529c-aa4d-4763-b2b6-4d614ec7dc00&pf_rd_r=V5P6J3QDV0DJFCGAX75B&pd_rd_wg=7QXj5&pd_rd_r=d4de3347-4a13-44e2-a039-7528adc9aea8&pd_rd_i=B010N1SPRK&psc=1)
- [Diffused Rectangle 5mm RGB Led](https://www.adafruit.com/product/2739)
- [Protoboard](https://www.amazon.com/EPLZON-Solder-able-Breadboard-Electronics-Compatible/dp/B09WZXHMDG/ref=asc_df_B09WZXHMDG/?tag=hyprod-20&linkCode=df0&hvadid=598524192612&hvpos=&hvnetw=g&hvrand=20696255451240229&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1021721&hvtargid=pla-1677878354633&psc=1)
- Generic Pushbutton
- 22g Solid Wire

I don't feel a full instruction list is necessary, and almost anyone with basic development and electronic skills should be able to replicate this. The only things you should need to change in code are the MQTT Topic (each set of devices needs their own topic), the mqtt_user (needs to be unique to each board), and PIN numbers for the LED and button.

## Future

As of right now, I don't have plans to continue working on this project. I think nice features to add would be more options in the setup portal (changing the broker address, port, and the mqtt_username from the portal would be great), but as of now that's not necessary. I can also imagine a much more finished project with a larger / more powerful LED, nicer button, and a full 3D printed or wood worked enclosure.