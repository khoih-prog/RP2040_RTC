/****************************************************************************************************************************
  RP2040_RTC.h
  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields

  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
  Version: 1.0.8

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      13/06/2021 Initial release to support RP2040-based boards using internal RTC
  1.0.1  K Hoang      14/06/2021 Add mbed_nano architecture to library.properties
  1.0.2  K Hoang      16/06/2021 Fix bug in display alarm time
  1.0.3  K Hoang      23/06/2021 Add simple example with manual time input
  1.0.4  K Hoang      26/06/2021 Using TimeLib instead of Time
  1.0.5  K Hoang      30/09/2021 Fix examples' issue with Nano_RP2040_Connect
  1.0.6  K Hoang      22/10/2021 Fix platform in library.json for PIO
  1.0.7  K Hoang      01/11/2021 Fix bug in rtc_set_datetime()
  1.0.8  K Hoang      20/01/2022 Update dependency
*****************************************************************************************************************************/

#pragma once

#ifndef RP2040_RTC_H
#define RP2040_RTC_H

#define RP2040_RTC_VERSION            "RP2040_RTC v1.0.8"

#define RP2040_RTC_VERSION_MAJOR      1
#define RP2040_RTC_VERSION_MINOR      0
#define RP2040_RTC_VERSION_PATCH      8

#define RP2040_RTC_VERSION_INT        1000008

#if !defined(RTC_DEBUG)
  #define RTC_DEBUG     false
#endif

#include <Arduino.h>

extern "C" 
{
  typedef void(* rtc_callback_t )(void);
  
  void rtc_init           (void);
  bool rtc_set_datetime   (datetime_t *t);
  bool rtc_get_datetime   (datetime_t *t);
  void rtc_set_alarm      (datetime_t *t, rtc_callback_t user_callback);
  void rtc_disable_alarm  (void);
  void rtc_enable_alarm   (void);

  bool rtc_alarm_repeats(datetime_t *t);

  void datetime_to_str(char *buf, uint buf_size, const datetime_t *t);
}

#include "DateTime_Generic.h"


#endif    // RP2040_RTC_H
