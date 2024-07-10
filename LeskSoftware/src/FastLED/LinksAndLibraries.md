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
