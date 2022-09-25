# RP2040_RTC Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/RP2040_RTC.svg?)](https://www.ardu-badge.com/RP2040_RTC)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/RP2040_RTC.svg)](https://github.com/khoih-prog/RP2040_RTC/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/RP2040_RTC/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/RP2040_RTC.svg)](http://github.com/khoih-prog/RP2040_RTC/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this RP2040_RTC library](#why-do-we-need-this-rp2040_rtc-library)
  * [Features](#features)
  * [Why using ISR-based Alarm is better](#why-using-isr-based-alarm-is-better)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
  * [Currently supported WiFi shields/modules](#currently-supported-WiFi-shieldsmodules)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
* [Usage](#usage)
  * [1. Raspberry Pi Pico C/C++ SDK](#1-raspberry-pi-pico-cc++-sdk)
    * [1.1 Typedef](#11-typedef)
    * [1.2 SDK Function List](#12-sdk-function-list)
    * [1.3 SDK Function Documentation](#13-sdk-function-documentation)
  * [2. Library Functions](#2-library-functions)
    * [2.1 Typedef](#21-typedef)
    * [2.2 Library Function List](#22-library-function-list)
* [Examples](#examples)
  * [ 1. RP2040_RTC_Alarm](examples/Alarm/RP2040_RTC_Alarm)
  * [ 2. RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet)
  * [ 3. RP2040_RTC_Alarm_WiFiNINA](examples/Alarm/RP2040_RTC_Alarm_WiFiNINA)
  * [ 4. RP2040_RTC_Alarm_RP2040W](examples/Alarm/RP2040_RTC_Alarm_RP2040W)
  * [ 5. RP2040_RTC_Time](examples/Time/RP2040_RTC_Time)
  * [ 6. RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet)
  * [ 7. RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA)
  * [ 8. RP2040_RTC_Time_RP2040W](examples/Time/RP2040_RTC_Time_RP2040W)
* [Example RP2040_RTC_Time_WiFiNINA](#example-rp2040_rtc_time_wifinina)
  * [ 1. File RP2040_RTC_Time_WiFiNINA.ino](#1-file-rp2040_rtc_time_wifininaino)
  * [ 2. File defines.h](#2-file-definesh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. RP2040_RTC_Time_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library](#1-rp2040_rtc_time_ethernet-on-raspberry_pi_pico-with-w5x00-using-Ethernet_Generic-library)
  * [2. RP2040_RTC_Time_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library](#2-rp2040_rtc_time_ethernet-on-mbed-raspberry_pi_pico-with-w5x00-using-Ethernet_Generic-library)
  * [3. RP2040_RTC_Time_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library](#3-rp2040_rtc_time_wifinina-on-mbed-nano_rp2040_connect-with-wifinina-using-wifinina_generic-library)
  * [4. RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library](#4-rp2040_rtc_alarm_ethernet-on-raspberry_pi_pico-with-w5x00-using-Ethernet_Generic-library)
    * [4.1 Repeatitive Alarm](#41-repeatitive-alarm)
    * [4.2 One-shot Alarm](#42-one-shot-alarm)
  * [5. RP2040_RTC_Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library](#5-rp2040_rtc_alarm_ethernet-on-mbed-raspberry_pi_pico-with-w5x00-using-Ethernet_Generic-library)
    * [5.1 Repeatitive Alarm](#51-repeatitive-alarm)
    * [5.2 One-shot Alarm](#52-one-shot-alarm)
  * [6. RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library](#6-rp2040_rtc_alarm_wifinina-on-mbed-nano_rp2040_connect-with-wifinina-using-wifinina_generic-library)
    * [6.1 Repeatitive Alarm](#61-repeatitive-alarm)
    * [6.2 One-shot Alarm](#62-one-shot-alarm)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [RP2040_RTC library](https://github.com/khoih-prog/RP2040_RTC)

## Features

This is an Arduino library for **RP2040-based RTC**

```
The RTC keeps track of time in human readable format and generates events when the time is equal to a preset value.
Think of a digital clock, not epoch time used by most computers. There are seven fields, one each for year (12 bit),
month (4 bit), day (5 bit), day of the week (3 bit), hour (5 bit) minute (6 bit) and second (6 bit), storing the data in binary
format.
```

The examples will demonstrate how to get the UTC time from NTP server, then update the RTC to make sure the time is perfectly correct.


### Why using ISR-based Alarm is better

Imagine you have a system with a **mission-critical** function, measuring water level and control the sump pump or doing something much more important. You normally use a software timer to poll, or even place the function in loop(). But what if another function is **blocking** the loop() or setup().

So your function **might not be executed, and the result would be disastrous.**

You'd prefer to have your function called, no matter what happening with other functions (busy loop, bug, etc.).

The correct choice is to use an ISR-based Alarm with **Interrupt** to call your function.

These ISR-based Alarm, using interrupt, still work even if other functions are blocking. Moreover, they are much more **precise** (certainly depending on clock frequency accuracy) than other software timers using millis() or micros(). That's necessary if you need to measure some data requiring better accuracy.

Functions using normal software timers, relying on loop() and calling millis(), won't work if the loop() or setup() is blocked by certain operation. For example, certain function is blocking while it's connecting to WiFi or some services.

The catch is **your function is now part of an ISR (Interrupt Service Routine), and must be lean / mean, and follow certain rules.** More to read on:

[**HOWTO Attach Interrupt**](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

---

### Currently supported Boards

1. RP2040-based boards, such as **NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, RASPBERRY_PI_PICO_W, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico)

#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library
2. W5100S shield /module, using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library, such as [**WIZnet Ethernet HAT**](https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat) and [**W5100S-EVB-Pico**](https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico)

#### Currently supported WiFi shields/modules

1. `WiFiNINA` using [`WiFiNINA_Generic`](https://github.com/khoih-prog/WiFiNINA_Generic) library
2. `CYW43439 WiFi` with RASPBERRY_PI_PICO_W using [arduino-pico](https://github.com/earlephilhower/arduino-pico) core


---
---


## Prerequisites

1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
2. [`Arduino mbed_rp2040 core 3.3.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
3. [`Earle Philhower's arduino-pico core v2.5.4+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)

4. [`Timezone_Generic library v1.10.0+`](https://github.com/khoih-prog/Timezone_Generic) to use examples using Timezone. [![GitHub release](https://img.shields.io/github/release/khoih-prog/Timezone_Generic.svg)](https://github.com/khoih-prog/Timezone_Generic/releases/latest)
5. [`WiFiNINA_Generic library v1.8.14-6+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. [![GitHub release](https://img.shields.io/github/release/khoih-prog/WiFiNINA_Generic.svg)](https://github.com/khoih-prog/WiFiNINA_Generic/releases/latest)

6. Depending on which Ethernet card/module/shield you're using:
   - [`Ethernet_Generic library v2.6.1+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
   - [`EthernetENC library v2.0.3+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**RP2040_RTC**](https://github.com/khoih-prog/RP2040_RTC), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/RP2040_RTC.svg?)](https://www.ardu-badge.com/RP2040_RTC) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**RP2040_RTC**](https://github.com/khoih-prog/RP2040_RTC) page.
2. Download the latest release `RP2040_RTC-main.zip`.
3. Extract the zip file to `RP2040_RTC-main` directory 
4. Copy whole `RP2040_RTC-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**RP2040_RTC** library](https://registry.platformio.org/libraries/khoih-prog/RP2040_RTC) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/RP2040_RTC/installation). Search for **RP2040_RTC** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

---
---

## Usage

### 1. Raspberry Pi Pico C/C++ SDK

From [Raspberry Pi Pico C/C++ SDK](https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf)

### 1.1. Typedef

```
typedef void(* rtc_callback_t )(void);

typedef struct 
{
  int16_t year;     ///< 0..4095
  int8_t  month;    ///< 1..12, 1 is January
  int8_t  day;      ///< 1..28,29,30,31 depending on month
  int8_t  dotw;     ///< 0..6, 0 is Sunday
  int8_t  hour;     ///< 0..23
  int8_t  min;      ///< 0..59
  int8_t  sec;      ///< 0..59
} datetime_t;
```

### 1.2. SDK Function List

```
void rtc_init (void);
bool rtc_set_datetime (datetime_t *t);
bool rtc_get_datetime (datetime_t *t);
bool rtc_running (void);
void rtc_set_alarm (datetime_t *t, rtc_callback_t user_callback);
void rtc_enable_alarm (void);
void rtc_disable_alarm (void);

// Not very good to use
void datetime_to_str (char *buf, uint buf_size, const datetime_t *t);
```

### 1.3. SDK Function Documentation

Use one of these functions with **interval in unsigned long microseconds**

#### rtc_disable_alarm

`void rtc_disable_alarm (void)`

Disable the RTC alarm (if active)

#### rtc_enable_alarm

`void rtc_enable_alarm (void)`

Enable the RTC alarm (if inactive)

#### rtc_get_datetime

`bool rtc_get_datetime (datetime_t *t)`

Get the current time from the RTC.

**Parameters**

• `t` : Pointer to a datetime_t structure to receive the current RTC time

**Returns**

• `true` if datetime is valid, `false` if the RTC is not running.


#### rtc_init

`void rtc_init (void)`

Initialise the RTC system.

#### rtc_running

`bool rtc_running (void)`

Is the RTC running?

#### rtc_set_alarm

`void rtc_set_alarm (datetime_t *t, rtc_callback_t user_callback)`

Set a time in the future for the RTC to call a user provided callback.

**Parameters**

• `t` : Pointer to a datetime_t structure containing a time in the future to fire the alarm. Any values set to -1 will not be
matched on.
• `user_callback` : pointer to a `rtc_callback_t` to call when the alarm fires

#### rtc_set_datetime

`bool rtc_set_datetime (datetime_t *t)`

Set the RTC to the specified time.

**Parameters**

• `t` : Pointer to a datetime_t structure contains time to set

**Returns**

• `true` if set, `false` if the passed in datetime was invalid.


####  datetime_to_str

`void datetime_to_str (char *buf, uint buf_size, const datetime_t *t)`

Convert a datetime_t structure to a string.

**Parameters**

• `buf` : character buffer to accept generated string
• `buf_size` : The size of the passed in buffer
• `t` : The datetime to be converted

---

### 2. Library Functions

### 2.1. Typedef

```
class TimeSpan;

class DateTime;

/** ISO 8601 Timestamp function */
enum timestampOpt 
{
  TIMESTAMP_FULL, // YYYY-MM-DDTHH:MM:SS
  TIMESTAMP_TIME, // HH:MM:SS
  TIMESTAMP_DATE  // YYYY-MM-DD
};
```

### 2.2. Library Function List

```
class DateTime
{
  DateTime (uint32_t t = SECONDS_FROM_1970_TO_2000);
  DateTime (const uint16_t year, const uint8_t month, const uint8_t day, const uint8_t hour = 0, const uint8_t min = 0, const uint8_t sec = 0);
  DateTime (const DateTime& copy);
  DateTime (const tmElements_t& tm);

  // To use with RP2040 datetime_t struct
  DateTime (const datetime_t &tm);

  tmElements_t get_tmElements_t();
  void setFrom_tmElements_t(const tmElements_t& tm);
  time_t get_time_t();
  void setFrom_time_t(const time_t& timeInput);

  uint16_t year() const;
  uint8_t month() const;
  uint8_t day() const;
  uint8_t hour() const;
  uint8_t minute() const;
  uint8_t second() const;
  uint16_t yearOffset() const;
  uint8_t dayOfTheWeek() const;

  /** 32-bit times as seconds since 1/1/2000 */
  long secondstime() const;

  /** 32-bit times as seconds since 1/1/1970 */
  uint32_t unixtime() const;

  /** ISO 8601 Timestamp function */
  String timestamp(timestampOpt opt = TIMESTAMP_FULL)
}
```


---
---

### Examples 

 1. [RP2040_RTC_Alarm](examples/Alarm/RP2040_RTC_Alarm)
 2. [RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet)
 3. [RP2040_RTC_Alarm_WiFiNINA](examples/Alarm/RP2040_RTC_Alarm_WiFiNINA)
 4. [RP2040_RTC_Alarm_RP2040W](examples/Alarm/RP2040_RTC_Alarm_RP2040W) **New**
 5. [RP2040_RTC_Time](examples/Time/RP2040_RTC_Time)
 6. [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet)
 7. [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA)
 8. [RP2040_RTC_Time_RP2040W](examples/Time/RP2040_RTC_Time_RP2040W) **New**

---
---

### Example [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA)

#### 1. File [RP2040_RTC_Time_WiFiNINA.ino](examples/Time/RP2040_RTC_Time_WiFiNINA/RP2040_RTC_Time_WiFiNINA.ino)

https://github.com/khoih-prog/RP2040_RTC/blob/e8a9591a9460cb478d88de0d130f8aeaf97fa8f7/examples/Time/RP2040_RTC_Time_WiFiNINA/RP2040_RTC_Time_WiFiNINA.ino#L11-L276

#### 2. File [defines.h](examples/Time/RP2040_RTC_Time_WiFiNINA/defines.h)

https://github.com/khoih-prog/RP2040_RTC/blob/e8a9591a9460cb478d88de0d130f8aeaf97fa8f7/examples/Time/RP2040_RTC_Time_WiFiNINA/defines.h#L11-L75

---
---

### Debug Terminal Output Samples

#### 1. RP2040_RTC_Time_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet) on RASPBERRY_PI_PICO with W5100S using Ethernet_Generic Library

```
Start RP2040_RTC_Time_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 10
You're connected to the network, IP = 192.168.2.95
Packet received
Seconds since Jan 1 1900 = 3859851978
Unix time = 1650863178
The UTC time is 5:06:18
============================
05:06:19 Mon 25 Apr 2022 UTC
01:06:19 Mon 25 Apr 2022 EDT
```

---

#### 2. RP2040_RTC_Time_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library


```
Start RP2040_RTC_Time_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 1
You're connected to the network, IP = 192.168.2.102
Packet received
Seconds since Jan 1 1900 = 3859851547
Unix time = 1650862747
The UTC time is 4:59:07
============================
04:59:08 Mon 25 Apr 2022 UTC
00:59:08 Mon 25 Apr 2022 EDT
============================
05:00:08 Mon 25 Apr 2022 UTC
01:00:08 Mon 25 Apr 2022 EDT
============================
05:01:08 Mon 25 Apr 2022 UTC
01:01:08 Mon 25 Apr 2022 EDT
```

---

#### 3. RP2040_RTC_Time_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Start RP2040_RTC_Time_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Packet received
Seconds since Jan 1 1900 = 3859851547
Unix time = 1650862747
The UTC time is 4:59:07
============================
04:59:08 Mon 25 Apr 2022 UTC
00:59:08 Mon 25 Apr 2022 EDT
```

---

#### 4. RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet) on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

#### 4.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 12
You're connected to the network, IP = 192.168.2.99
Packet received
Seconds since Jan 1 1900 = 3859852325
Unix time = 1650863525
The UTC time is 5:12:05
============================
05:12:06 Mon 25 Apr 2022 UTC
01:12:06 Mon 25 Apr 2022 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:13:05 Mon 25 Apr 2022 UTC
01:13:05 Mon 25 Apr 2022 EDT
============================
05:13:06 Mon 25 Apr 2022 UTC
01:13:06 Mon 25 Apr 2022 EDT
```

#### 4.2. One-shot Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] Board : RASPBERRY_PI_PICO , setCsPin: 17
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 17
You're connected to the network, IP = 192.168.2.101
Packet received
Seconds since Jan 1 1900 = 3859852325
Unix time = 1650863525
The UTC time is 5:12:05
============================
05:12:06 Mon 25 Apr 2022 UTC
01:12:06 Mon 25 Apr 2022 EDT
Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:13:05 Mon 25 Apr 2022 UTC
01:13:05 Mon 25 Apr 2022 EDT
```

---

#### 5. RP2040_RTC_Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

#### 5.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 19
You're connected to the network, IP = 192.168.2.104
Packet received
Seconds since Jan 1 1900 = 3859852627
Unix time = 1650863827
The UTC time is 5:17:07
============================
05:17:08 Mon 25 Apr 2022 UTC
01:17:08 Mon 25 Apr 2022 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:18:05 Mon 25 Apr 2022 UTC
01:18:05 Mon 25 Apr 2022 EDT
============================
05:18:08 Mon 25 Apr 2022 UTC
01:18:08 Mon 25 Apr 2022 EDT
```

#### 5.2. One-shot Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
[EWS] =========== USE_ETHERNET_GENERIC ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] Board : RASPBERRY_PI_PICO , setCsPin: 17
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 17
You're connected to the network, IP = 192.168.2.101
Packet received
Seconds since Jan 1 1900 = 3859852627
Unix time = 1650863827
The UTC time is 5:17:07
============================
05:17:08 Mon 25 Apr 2022 UTC
01:17:08 Mon 25 Apr 2022 EDT
Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:18:05 Mon 25 Apr 2022 UTC
01:18:05 Mon 25 Apr 2022 EDT
```

---

#### 6. RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_WiFiNINA](examples/Alarm/RP2040_RTC_Alarm_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

#### 6.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.125
Packet received
Seconds since Jan 1 1900 = 3859852627
Unix time = 1650863827
The UTC time is 5:17:07
============================
05:17:08 Mon 25 Apr 2022 UTC
01:17:08 Mon 25 Apr 2022 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:18:05 Mon 25 Apr 2022 UTC
01:18:05 Mon 25 Apr 2022 EDT
============================
05:18:08 Mon 25 Apr 2022 UTC
01:18:08 Mon 25 Apr 2022 EDT
```

#### 6.2. One-shot Alarm


```
Start RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.1.1
Timezone_Generic v1.10.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.125
Packet received
Seconds since Jan 1 1900 = 3859852627
Unix time = 1650863827
The UTC time is 5:17:07
============================
05:17:08 Mon 25 Apr 2022 UTC
01:17:08 Mon 25 Apr 2022 EDT
Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
05:18:05 Mon 25 Apr 2022 UTC
01:18:05 Mon 25 Apr 2022 EDT
```

---
---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---


### Issues

Submit issues to: [RP2040_RTC issues](https://github.com/khoih-prog/RP2040_RTC/issues)

---

## TO DO

1. Search for bug and improvement.


---

## DONE

1. Basic RTC-wrapper library for **RP2040-based boards, such as NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico).
2. Add Version String 
3. Add Table of Contents
4. Add simple examples with manual time input
5. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
6. Add support to `SPI1` for `RP2040` using [`Earle Philhower's arduino-pico` core](https://github.com/earlephilhower/arduino-pico)
7. Add support to WIZNet W5100S, such as  [**WIZnet Ethernet HAT**](https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat) and [**W5100S-EVB-Pico**](https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico)
8. Add support to `RP2040W` using `CYW43439 WiFi` with [`Earle Philhower's arduino-pico` core](https://github.com/earlephilhower/arduino-pico)

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [kenb2054](https://github.com/kenb2054) to report bugs in [Libraries updated to support new RP2040-based boards (RASPBERRY_PI_PICO, etc.) #43](https://forum.arduino.cc/t/libraries-updated-to-support-new-rp2040-based-boards-raspberry-pi-pico-etc/860353/43) leading to v1.0.4
2. Thanks to [josephchrzempiec](https://github.com/josephchrzempiec) to report bugs leading to v1.0.5
3. Thanks to [Maximilian Gerhardt](https://github.com/maxgerhardt) 

- to create the PR [Correct platform name #2](https://github.com/khoih-prog/RP2040_RTC/pull/2) leading to v1.0.6
- to create perfect bug report [Library converts datetime_t incorrectly, causing example to fail #4](https://github.com/khoih-prog/RP2040_RTC/issues/4) leading to v1.0.7

<table>
  <tr>
    <td align="center"><a href="https://github.com/kenb2054"><img src="https://github.com/kenb2054.png" width="100px;" alt="kenb2054"/><br /><sub><b>kenb2054</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/josephchrzempiec"><img src="https://github.com/josephchrzempiec.png" width="100px;" alt="josephchrzempiec"/><br /><sub><b>josephchrzempiec</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/maxgerhardt"><img src="https://github.com/maxgerhardt.png" width="100px;" alt="maxgerhardt"/><br /><sub><b>⭐️ Maximilian Gerhardt</b></sub></a><br /></td>
  </tr> 
</table>

---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/RP2040_RTC/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang


