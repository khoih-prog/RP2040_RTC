/****************************************************************************************************************************
  defines.h
  
  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields
  
  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             3
#define _WIFININA_LOGLEVEL_         4

#define USE_WIFI_NINA         true
//#define USE_WIFI_NINA         false

#if USE_WIFI_NINA
  #warning Using WiFiNINA using WiFiNINA_Generic Library
  #define SHIELD_TYPE           "WiFiNINA using WiFiNINA_Generic Library"
#endif

#if ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) )
  #if defined(WIFININA_USE_RP2040)
    #undef WIFININA_USE_RP2040
  #endif
  #define WIFININA_USE_RP2040      true

  #if defined(ARDUINO_ARCH_MBED)

    #if defined(BOARD_NAME)
      #undef BOARD_NAME
    #endif

    #if defined(ARDUINO_NANO_RP2040_CONNECT)
      #define BOARD_NAME      "MBED NANO_RP2040_CONNECT"
    #elif defined(ARDUINO_RASPBERRY_PI_PICO) 
      #define BOARD_NAME      "MBED RASPBERRY_PI_PICO"
    #elif defined(ARDUINO_ADAFRUIT_FEATHER_RP2040)
      #define BOARD_NAME      "MBED DAFRUIT_FEATHER_RP2040"
    #elif defined(ARDUINO_GENERIC_RP2040)
      #define BOARD_NAME      "MBED GENERIC_RP2040"
    #else
      #define BOARD_NAME      "MBED Unknown RP2040"
    #endif
    
  #endif
  
#else
  #error This code is not designed to run on RP2040 platform! Please check your Tools->Board setting.
#endif

#ifndef BOARD_NAME
  #if defined(ARDUINO_BOARD)
    #define BOARD_NAME      ARDUINO_BOARD
  #else   
    #define BOARD_NAME      BOARD_TYPE
  #endif  
#endif

#include <RP2040_RTC.h>
#include <WiFiNINA_Generic.h>

char ssid[] = "ssid";             // your network SSID (name)
char pass[] = "12345678";         // your network password

#endif    //defines_h
