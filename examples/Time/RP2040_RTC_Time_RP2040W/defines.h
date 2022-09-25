/****************************************************************************************************************************
  defines.h
  
  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields
  
  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

// Debug Level from 0 to 4
#define _TZ_LOGLEVEL_       1

#if ( defined(ARDUINO_RASPBERRY_PI_PICO_W) )

  #if defined(ARDUINO_ARCH_MBED)

    #if defined(BOARD_NAME)
      #undef BOARD_NAME
    #endif
    
    // Not supported yet. Just for the future
    #define BOARD_NAME      "MBED RASPBERRY_PI_PICO_W"

    #error Core mbed_rp2040 not supporting RP2040W yet.
    
  #endif
  
#else
  #error This code is designed to run on RP2040W platform! Please check your Tools->Board setting.
#endif

#ifndef BOARD_NAME
  #if defined(ARDUINO_BOARD)
    #define BOARD_NAME      ARDUINO_BOARD
  #endif  
#endif

#include <RP2040_RTC.h>
#include <WiFi.h>

char ssid[] = "ssid";             // your network SSID (name)
char pass[] = "12345678";         // your network password

#endif    //defines_h
