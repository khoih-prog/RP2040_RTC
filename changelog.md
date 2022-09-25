# RP2040_RTC Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/RP2040_RTC.svg?)](https://www.ardu-badge.com/RP2040_RTC)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/RP2040_RTC.svg)](https://github.com/khoih-prog/RP2040_RTC/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/RP2040_RTC/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/RP2040_RTC.svg)](http://github.com/khoih-prog/RP2040_RTC/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.1.1](#releases-v111)
  * [Releases v1.1.0](#releases-v110)
  * [Releases v1.0.8](#releases-v108)
  * [Releases v1.0.7](#releases-v107)
  * [Releases v1.0.6](#releases-v106)
  * [Releases v1.0.5](#releases-v105)
  * [Releases v1.0.4](#releases-v104)
  * [Releases v1.0.3](#releases-v103)
  * [Releases v1.0.2](#releases-v102)
  * [Releases v1.0.1](#releases-v101)
  * [Initial Releases v1.0.0](#initial-releases-v100)

---
---

## Changelog

### Releases v1.1.1

1. Add support to `RP2040W` using `CYW43439 WiFi` with `arduino-pico` core

### Releases v1.1.0

1. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
2. Add support to `SPI1` for `RP2040` using [`Earle Philhower's arduino-pico` core](https://github.com/earlephilhower/arduino-pico)
3. Add support to WIZNet W5100S, such as  [**WIZnet Ethernet HAT**](https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat) and [**W5100S-EVB-Pico**](https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico)

### Releases v1.0.8

1. Update dependency on [Timezone_Generic Library](https://github.com/khoih-prog/Timezone_Generic)
2. Update examples

### Releases v1.0.7

1. Fix bug in rtc_set_datetime(). Check [Library converts datetime_t incorrectly, causing example to fail #4](https://github.com/khoih-prog/RP2040_RTC/issues/4)

### Releases v1.0.6

1. Fix platform in `library.json`

### Releases v1.0.5

1. Fix examples' issue with Nano_RP2040_Connect

### Releases v1.0.4

1. Using TimeLib instead of Time to avoid case-insensitive issue with Windows and MacOS.

### Releases v1.0.3

1. Add simple examples with manual time input

### Releases v1.0.2

1. Fix bug in display alarm time due to buggy `datetime_to_str()` function

### Releases v1.0.1

1. Fix `library.properties` to add `mbed_nano` architecture for **NANO_RP2040_CONNECT** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

### Initial Releases v1.0.0

1. Initial coding to support RP2040-based boards such as **NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico).


---
---

## Prerequisites

1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
2. [`Arduino mbed_rp2040 core 2.2.0+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
3. [`Earle Philhower's arduino-pico core v1.8.8+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)

4. [`Timezone_Generic library v1.5.0+`](https://github.com/khoih-prog/Timezone_Generic) to use examples using Timezone. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic)
5. [`WiFiNINA_Generic library v1.8.11+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using `WiFiNINA_Generic` library for Nano-RP2040-Connect boards.

6. Depending on which Ethernet card/module/shield you're using:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
   - [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**

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
3. Install [**RP2040_RTC** library](https://platformio.org/lib/show/12433/RP2040_RTC) or [**RP2040_RTC** library](https://platformio.org/lib/show/12433/RP2040_RTC) by using [Library Manager](https://platformio.org/lib/show/12433/RP2040_RTC/installation). Search for **RP2040_RTC** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
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
 4. [RP2040_RTC_Time](examples/Time/RP2040_RTC_Time)
 5. [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet)
 6. [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA)

---
---

### Example [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA)

#### 1. File [RP2040_RTC_Time_WiFiNINA.ino](examples/Time/RP2040_RTC_Time_WiFiNINA/RP2040_RTC_Time_WiFiNINA.ino)

```
// Important notes: Currently, RP2040-based boards RTC has no battery backup. So the time will be lost when power down
// Therefore, NTP client is necessary to get NTP time and update RTC.

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

//////////////////////////////////////////

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First, Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
Timezone *myTZ;

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

int status = WL_IDLE_STATUS;      // the Wifi radio's status

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

datetime_t  currTime;
char        datetime_buf[256];

// send an NTP request to the time server at the given address
void sendNTPpacket(char *ntpSrv)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpSrv, 123); //NTP requests are to port 123

  Udp.write(packetBuffer, NTP_PACKET_SIZE);

  Udp.endPacket();
}

void getNTPTime()
{
  static bool gotCurrentTime = false;

  // Just get the correct ime once
  if (!gotCurrentTime)
  {
    sendNTPpacket(timeServer); // send an NTP packet to a time server
    // wait to see if a reply is available
    delay(1000);

    if (Udp.parsePacket())
    {
      Serial.println(F("Packet received"));
      // We've received a packet, read the data from it
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

      //the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, esxtract the two words:

      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      Serial.print(F("Seconds since Jan 1 1900 = "));
      Serial.println(secsSince1900);

      // now convert NTP time into everyday time:
      Serial.print(F("Unix time = "));
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;

      // print Unix time:
      Serial.println(epoch);
      
      // Get the time_t from epoch
      time_t epoch_t = epoch;

      // set the system time to UTC
      // warning: assumes that compileTime() returns US EDT
      // adjust the following line accordingly if you're in another time zone
      setTime(epoch_t);

      // Update RTC
      // Can use either one of these functions
      
      // 1) DateTime(tmElements_t). Must create tmElements_t if not present
      //tmElements_t tm;
      //breakTime(epoch_t, tm);
      //rtc_set_datetime( DateTime(tm) );
      
      // 2) DateTime(year, month, day, hour, min, sec)
      //rtc_set_datetime( DateTime(year(epoch_t), month(epoch_t), day(epoch_t), hour(epoch_t), minute(epoch_t), second(epoch_t) ) );

      // 3) DateTime (time_t)
      //rtc_set_datetime( DateTime(epoch_t) );

      // 4) DateTime(unsigned long epoch). The best and easiest way
      //rtc_set_datetime( DateTime((uint32_t) epoch) );

      // New function in DateTime_Generic.h
      while( ! rtc_set_datetime(DateTime((uint32_t) epoch)) )
      {
        Serial.println(F("rtc_set_datetime failed"));
        sleep_ms(1);
      }     
      
      // print the hour, minute and second:
      Serial.print(F("The UTC time is "));        // UTC is the time at Greenwich Meridian (GMT)
      Serial.print((epoch  % 86400L) / 3600);     // print the hour (86400 equals secs per day)
      Serial.print(':');

      if (((epoch % 3600) / 60) < 10)
      {
        // In the first 10 minutes of each hour, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial.print(':');

      if ((epoch % 60) < 10)
      {
        // In the first 10 seconds of each minute, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.println(epoch % 60); // print the second

      gotCurrentTime = true;
    }
    else
    {
      // wait ten seconds before asking for the time again
      delay(10000);
    }
  }
}

//////////////////////////////////////////

// format and print a time_t value, with a time zone appended.
void printDateTime(time_t t, const char *tz)
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%.2d:%.2d:%.2d %s %.2d %s %d %s",
          hour(t), minute(t), second(t), dayShortStr(weekday(t)), day(t), m, year(t), tz);
  Serial.println(buf);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart RP2040_RTC_Time_WiFiNINA on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(RP2040_RTC_VERSION);
  Serial.println(TIMEZONE_GENERIC_VERSION);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println(F("Please upgrade the firmware"));
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    Serial.print(F("Connecting to WPA SSID: "));
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

  myTZ = new Timezone(myDST, mySTD);

  // Start the RTC
  rtc_init();

  Udp.begin(localPort);
}

void displayTime()
{
  rtc_get_datetime(&currTime);

  // Display time from RTC
  DateTime now = DateTime(currTime); 

  time_t utc = now.get_time_t();
  time_t local = myTZ->toLocal(utc, &tcr);

  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
}

void displayRTCTime()
{
  static unsigned long displayRTCTime_timeout = 0;

#define DISPLAY_RTC_INTERVAL     60000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to display frequently.
  if ((millis() > displayRTCTime_timeout) || (displayRTCTime_timeout == 0))
  {
    Serial.println("============================");
    displayTime();

    displayRTCTime_timeout = millis() + DISPLAY_RTC_INTERVAL;
  }
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC to have better accuracy
  getNTPTime();

  displayRTCTime();
}
```

#### 2. File [defines.h](examples/Time/RP2040_RTC_Time_WiFiNINA/defines.h)

```
#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             3
#define _WIFININA_LOGLEVEL_         3

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
  #error This code is designed to run on RP2040 platform! Please check your Tools->Board setting.
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
```

---
---

### Debug Terminal Output Samples

#### 1. RP2040_RTC_Time_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet) on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

```
Start RP2040_RTC_Time_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
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
Using mac index = 10
You're connected to the network, IP = 192.168.2.94
Packet received
Seconds since Jan 1 1900 = 3832635641
Unix time = 1623646841
The UTC time is 5:00:41
============================
05:00:42 Mon 14 Jun 2021 UTC
01:00:42 Mon 14 Jun 2021 EDT
============================
05:01:42 Mon 14 Jun 2021 UTC
01:01:42 Mon 14 Jun 2021 EDT
```

---

#### 2. RP2040_RTC_Time_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [RP2040_RTC_Time_Ethernet](examples/Time/RP2040_RTC_Time_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library


```
Start RP2040_RTC_Time_Ethernet on  RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 3
[EWS] MISO: 4
[EWS] SCK: 2
[EWS] SS: 5
[EWS] =========================
[EWS] Board : MBED RASPBERRY_PI_PICO , setCsPin: 5
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
Using mac index = 19
You're connected to the network, IP = 192.168.2.104
Packet received
Seconds since Jan 1 1900 = 3832635800
Unix time = 1623647000
The UTC time is 5:03:20
============================
05:03:21 Mon 14 Jun 2021 UTC
01:03:21 Mon 14 Jun 2021 EDT
============================
05:04:21 Mon 14 Jun 2021 UTC
01:04:21 Mon 14 Jun 2021 EDT
```

---

#### 3. RP2040_RTC_Time_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Time_WiFiNINA](examples/Time/RP2040_RTC_Time_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Start RP2040_RTC_Time_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Packet received
Seconds since Jan 1 1900 = 3832636844
Unix time = 1623648044
The UTC time is 5:20:44
============================
05:20:45 Mon 14 Jun 2021 UTC
01:20:45 Mon 14 Jun 2021 EDT
============================
05:21:45 Mon 14 Jun 2021 UTC
01:21:45 Mon 14 Jun 2021 EDT
```

---

#### 4. RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet) on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

#### 4.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
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
Using mac index = 2
You're connected to the network, IP = 192.168.2.107
Packet received
Seconds since Jan 1 1900 = 3832883807
Unix time = 1623895007
The UTC time is 1:56:47
============================
01:56:48 Thu 17 Jun 2021 UTC
21:56:48 Wed 16 Jun 2021 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
01:57:05 Thu 17 Jun 2021 UTC
21:57:05 Wed 16 Jun 2021 EDT
============================
01:57:48 Thu 17 Jun 2021 UTC
21:57:48 Wed 16 Jun 2021 EDT
============================
Alarm @ 
01:58:05 Thu 17 Jun 2021 UTC
21:58:05 Wed 16 Jun 2021 EDT
============================
01:58:48 Thu 17 Jun 2021 UTC
21:58:48 Wed 16 Jun 2021 EDT
============================
Alarm @ 
01:59:05 Thu 17 Jun 2021 UTC
21:59:05 Wed 16 Jun 2021 EDT
```

#### 4.2. One-shot Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
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
Seconds since Jan 1 1900 = 3832639454
Unix time = 1623650654
The UTC time is 6:04:14
============================
06:04:15 Mon 14 Jun 2021 UTC
02:04:15 Mon 14 Jun 2021 EDT
Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
06:05:05 Mon 14 Jun 2021 UTC
02:05:05 Mon 14 Jun 2021 EDT
============================
06:05:15 Mon 14 Jun 2021 UTC
02:05:15 Mon 14 Jun 2021 EDT
============================
06:06:15 Mon 14 Jun 2021 UTC
02:06:15 Mon 14 Jun 2021 EDT
```

---

#### 5. RP2040_RTC_Alarm_Ethernet on MBED on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_Ethernet](examples/Alarm/RP2040_RTC_Alarm_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

#### 5.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 3
[EWS] MISO: 4
[EWS] SCK: 2
[EWS] SS: 5
[EWS] =========================
[EWS] Board : MBED RASPBERRY_PI_PICO , setCsPin: 5
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
Using mac index = 3
You're connected to the network, IP = 192.168.2.119
Packet received
Seconds since Jan 1 1900 = 3832642047
Unix time = 1623653247
The UTC time is 6:47:27
============================
06:47:28 Mon 14 Jun 2021 UTC
02:47:28 Mon 14 Jun 2021 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
06:48:05 Mon 14 Jun 2021 UTC
02:48:05 Mon 14 Jun 2021 EDT
============================
06:48:28 Mon 14 Jun 2021 UTC
02:48:28 Mon 14 Jun 2021 EDT
============================
Alarm @ 
06:49:05 Mon 14 Jun 2021 UTC
02:49:05 Mon 14 Jun 2021 EDT
============================
06:49:28 Mon 14 Jun 2021 UTC
02:49:28 Mon 14 Jun 2021 EDT
============================
Alarm @ 
06:50:05 Mon 14 Jun 2021 UTC
02:50:05 Mon 14 Jun 2021 EDT
============================
06:50:28 Mon 14 Jun 2021 UTC
02:50:28 Mon 14 Jun 2021 EDT
============================
Alarm @ 
06:51:05 Mon 14 Jun 2021 UTC
02:51:05 Mon 14 Jun 2021 EDT
```

#### 5.2. One-shot Alarm

```
Start RP2040_RTC_Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
[EWS] =========== USE_ETHERNET_LARGE ===========
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
Seconds since Jan 1 1900 = 3832639454
Unix time = 1623650654
The UTC time is 6:04:14
============================
06:04:15 Mon 14 Jun 2021 UTC
02:04:15 Mon 14 Jun 2021 EDT

Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
06:05:05 Mon 14 Jun 2021 UTC
02:05:05 Mon 14 Jun 2021 EDT
============================
06:05:15 Mon 14 Jun 2021 UTC
02:05:15 Mon 14 Jun 2021 EDT
============================
06:06:15 Mon 14 Jun 2021 UTC
02:06:15 Mon 14 Jun 2021 EDT
```

---

#### 6. RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

The following is the sample terminal output when running example [RP2040_RTC_Alarm_WiFiNINA](examples/Alarm/RP2040_RTC_Alarm_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

#### 6.1. Repeatitive Alarm

```
Start RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Packet received
Seconds since Jan 1 1900 = 3832884378
Unix time = 1623895578
The UTC time is 2:06:18
============================
02:06:19 Thu 17 Jun 2021 UTC
22:06:19 Wed 16 Jun 2021 EDT
Set Repeatitive Alarm @ alarmSeconds = 5
============================
Alarm @ 
02:07:05 Thu 17 Jun 2021 UTC
22:07:05 Wed 16 Jun 2021 EDT
============================
02:07:19 Thu 17 Jun 2021 UTC
22:07:19 Wed 16 Jun 2021 EDT
============================
Alarm @ 
02:08:05 Thu 17 Jun 2021 UTC
22:08:05 Wed 16 Jun 2021 EDT
============================
02:08:19 Thu 17 Jun 2021 UTC
22:08:19 Wed 16 Jun 2021 EDT
```

#### 6.2. One-shot Alarm


```
Start RP2040_RTC_Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
RP2040_RTC v1.0.4
Timezone_Generic v1.5.0
Please upgrade the firmware
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Packet received
Seconds since Jan 1 1900 = 3832885266
Unix time = 1623896466
The UTC time is 2:21:06
============================
02:21:07 Thu 17 Jun 2021 UTC
22:21:07 Wed 16 Jun 2021 EDT
Set One-time Alarm @ alarmSeconds = 5
============================
Alarm @ 
02:22:05 Thu 17 Jun 2021 UTC
22:22:05 Wed 16 Jun 2021 EDT
============================
02:22:07 Thu 17 Jun 2021 UTC
22:22:07 Wed 16 Jun 2021 EDT

```

---
---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

## Releases

### Releases v1.0.4

1. Using TimeLib instead of Time to avoid case-insensitive issue with Windows and MacOS.

### Releases v1.0.3

1. Add simple examples with manual time input

### Releases v1.0.2

1. Fix bug in display alarm time due to buggy `datetime_to_str()` function

### Releases v1.0.1

1. Fix `library.properties` to add `mbed_nano` architecture for **NANO_RP2040_CONNECT** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)

### Initial Releases v1.0.0

1. Initial coding to support RP2040-based boards such as **NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico).

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

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [kenb2054](https://github.com/kenb2054) to report bugs in [Libraries updated to support new RP2040-based boards (RASPBERRY_PI_PICO, etc.) #43](https://forum.arduino.cc/t/libraries-updated-to-support-new-rp2040-based-boards-raspberry-pi-pico-etc/860353/43) leading to v1.0.4

<table>
  <tr>
    <td align="center"><a href="https://github.com/kenb2054"><img src="https://github.com/kenb2054.png" width="100px;" alt="kenb2054"/><br /><sub><b>kenb2054</b></sub></a><br /></td>
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


