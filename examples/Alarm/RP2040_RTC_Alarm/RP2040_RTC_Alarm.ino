/****************************************************************************************************************************
  RP2040_RTC_Alarm.ino

  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields

  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
  Version: 1.0.3

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      13/06/2021 Initial release to support RP2040-based boards using internal RTC
  1.0.1  K Hoang      14/06/2021 Add mbed_nano architecture to library.properties
  1.0.2  K Hoang      16/06/2021 Fix bug in display alarm time
  1.0.3  K Hoang      23/06/2021 Add simple example with manual time input
 *****************************************************************************************************************************/

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

/*
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
*/

// Example set at 04:00:00 Wed 23 Jun 2021 UTC or 00:00:00 Wed 23 Jun 2021 EDT

datetime_t currTime = { 2021, 6, 23, 3, 4, 0, 0 };

datetime_t alarmT;
volatile bool alarmTriggered = false;

#define ALARM_AT_SECONDS          5
#define ALARM_REPEAT_FOREVER      true

//////////////////////////////////////////

// This is ISR. Be careful. No Serial.print here.
void rtcCallback()
{
  alarmTriggered = true;
}

void set_RTC_Alarm(datetime_t *alarmTime)
{
  rtc_set_alarm(alarmTime, rtcCallback);
}

void setAlarmOnce(uint8_t alarmSeconds)
{
  rtc_get_datetime(&alarmT);

  if ( alarmSeconds > alarmT.sec )
    alarmT.sec =  alarmSeconds;
  else
  {
    // Alarm in next minute
    alarmT.sec =  alarmSeconds;
    alarmT.min +=  1;
  }
  
  set_RTC_Alarm(&alarmT);

  Serial.print("Set One-time Alarm @ alarmSeconds = "); Serial.println(alarmSeconds);
}

void setAlarmRepeat(uint8_t alarmSeconds)
{
  // Redundant, but without this, many times alarm not set !!!
  rtc_get_datetime(&alarmT);
  
  alarmT.min = alarmT.hour = alarmT.day = alarmT.dotw = alarmT.month = alarmT.year = -1;
  alarmT.sec =  alarmSeconds;
  set_RTC_Alarm(&alarmT);

  Serial.print("Set Repeatitive Alarm @ alarmSeconds = "); Serial.println(alarmSeconds);
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

  Serial.print(F("\nStart RP2040_RTC_Alarm on ")); Serial.println(BOARD_NAME);
  Serial.println(RP2040_RTC_VERSION);
  Serial.println(TIMEZONE_GENERIC_VERSION);

  myTZ = new Timezone(myDST, mySTD);

  // Start the RTC
  rtc_init();

  rtc_set_datetime(&currTime);
}

bool setAlarmDone = false;

void setAlarm()
{
#if ALARM_REPEAT_FOREVER
  setAlarmRepeat(ALARM_AT_SECONDS);
#else
  setAlarmOnce(ALARM_AT_SECONDS);
#endif
  
  setAlarmDone = true;
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

#define DISPLAY_RTC_INTERVAL     10000L

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
  displayRTCTime();

  if (!setAlarmDone)
  {
    setAlarm();
  }

  if (alarmTriggered)
  {
    alarmTriggered = false;

    Serial.println("============================");
    Serial.println("Alarm @ ");
    displayTime();
  }  
}
