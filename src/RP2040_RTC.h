/****************************************************************************************************************************
  RP2040_RTC.h
  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields

  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
  Version: 1.0.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      13/06/2021 Initial release to support RP2040-based boards using internal RTC
  1.0.1  K Hoang      14/06/2021 Add mbed_nano architecture to library.properties
  1.0.2  K Hoang      16/06/2021 Fix bug in display alarm time
*****************************************************************************************************************************/

#pragma once

#ifndef RP2040_RTC_H
#define RP2040_RTC_H

#define RP2040_RTC_VERSION      "RP2040_RTC v1.0.2"

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
