<img src="front/bitbusy/public/busy.png" height=100> 

# Bitbusy   ![img](https://hackatime-badge.hackclub.com/U091LS2TL8M/bitbusy)
Bitbusy is a LED bar based on ESP32 microcontroller and WS2812 LEDs that indicates your work status, so your collegues won't distract you. 20$ alternative to the Busy Bar, that i've made for my mother's birthday
### Build and configure
Configure your device in ```src/defines.h```. Then, use ```./build-page.sh``` to build the wepbage. Then build and upload the filesystem image in PlatformIO. And only then upload the firmware. 
### Functionality
This device works like a timer: You choose time between 0-60 minutes and hit the main button to start your session. The device turns red, shows your status and time left.   

<img src="img/interface.png" height=200> <img src="img/build.png" height=200>


### Technologies
Made using platformio and arduino framework. Images and animations made in https://lopaka.app . Uses ESPAsyncWebServer and ArduinoJSON for web stuff and Adafruit GFX for graphics. Webpage made in svelte and typescript.
