# Here is the links and library to find ressources for the project

This .md file serves to list everything we need for the project in the future

## Led libraries

### WS2812FX
This library helps to manage led stripes. The only problem we have had right now is that it takes only 1 stripes that it divides in segments while we wanted several stripes. Used in WLED for the effects. Here is the link : https://github.com/kitesurfer1404/WS2812FX/blob/master/README.md

### FastLED
This is a great LED library, using to be able to instantiate several LEDd stripes. Problem being that it needs an instantiation with constans and that the number of functions is limited. But we have great hope it will be possible to overcome that.
Website : https://fastled.io
Github: https://github.com/FastLED/FastLED/tree/master
Wiki : https://fastled.io/docs/_pride2015_8ino-example.html (WHERE TO FIND THE DEFINITIONS)
Reddit Channel : https://www.reddit.com/r/FastLED/

### To check
- FastLED Hub --> Front end : https://github.com/srwi/FastLEDHub

## Uploading files in the ESP32

### SPIFFS
To upload files on a microcontroller we need the SPIFFS library which is basically a file system. This is needed for loading the XML file containing all the information.
Good explanation : https://randomnerdtutorials.com/esp32-vs-code-platformio-spiffs/

## XML Parser

Si I basically took inspiration from this video: 

## AsyncWebServer

To send request to the ESP, we need a web server that handles the requests. To do so, we will take inspiration from here: https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/

Here is the github repository : https://github.com/me-no-dev/ESPAsyncWebServer

Question?? Should we use this on a particular thread as it is asynchronous? Let's check later.
Apparently, it's not possible to send more than one answer to a request --> Need to check if

So, the part we are interested in now in the GitHub is: https://github.com/me-no-dev/ESPAsyncWebServer/tree/master?tab=readme-ov-file#respond-with-content-coming-from-a-file-containing-templates --> Respond with content coming from a file containing templates.

Need to investigate the JSON responses
Need to investigate the Param Rewrite With Matching

Feels as if there is event listener function but maybe with the sockets. Need to investigate.

## Serve file using SPIFFS

https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/

## ESP32 Web Server using SPIFFS (SPI Flash File System)

https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/

## ESP32 Async Web Server – Control Outputs with Arduino IDE (ESPAsyncWebServer library)

https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/

## Arduino JSON

https://arduinojson.org/v7/api/jsondocument/

## FastLED functions & Palettes

https://fastled.io/docs/group__lib8tion.html
https://fastled.io/tools/paletteknife/



Updated: 10th of July, 2024