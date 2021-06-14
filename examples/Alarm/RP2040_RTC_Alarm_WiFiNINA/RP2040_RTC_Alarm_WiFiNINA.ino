/****************************************************************************************************************************
  RP2040_RTC_Alarm_WiFiNINA.ino

  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields
  
  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      13/06/2021 Initial release to support RP2040-based boards using internal RTC
  1.0.1  K Hoang      14/06/2021 Add mbed_nano architecture to library.properties
 *****************************************************************************************************************************/

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

//////////////////////////////////////////

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First,  Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
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

//////////////////////////////////////////

datetime_t  currTime;
char        datetime_buf[256];

datetime_t alarmT;
volatile bool alarmTriggered = false;

#define ALARM_AT_SECONDS          5
#define ALARM_REPEAT_FOREVER      true

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
  // Redindant, but without this, many times alarm not set !!!
  rtc_get_datetime(&alarmT);
  
  alarmT.min = alarmT.hour = alarmT.day = alarmT.dotw = alarmT.month = alarmT.year = -1;
  alarmT.sec =  alarmSeconds;
  set_RTC_Alarm(&alarmT);

  Serial.print("Set Repeatitive Alarm @ alarmSeconds = "); Serial.println(alarmSeconds);
}

//////////////////////////////////////////

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

bool gotCurrentTime = false;

void getNTPTime()
{
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

//////////////////////////////////////////

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart RP2040_RTC_Alarm_WiFiNINA on ")); Serial.print(BOARD_NAME);
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

void displayRTCTime()
{
  static unsigned long displayRTCTime_timeout = 0;

#define DISPLAY_RTC_INTERVAL     60000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to display frequently.
  if ((millis() > displayRTCTime_timeout) || (displayRTCTime_timeout == 0))
  {
    rtc_get_datetime(&currTime);

    // Display time from RTC
    DateTime now = DateTime(currTime);

    Serial.println("============================");

    time_t utc = now.get_time_t();
    time_t local = myTZ->toLocal(utc, &tcr);

    printDateTime(utc, "UTC");
    printDateTime(local, tcr -> abbrev);

    displayRTCTime_timeout = millis() + DISPLAY_RTC_INTERVAL;
  }
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC to have better accuracy
  getNTPTime();

  displayRTCTime();

  if (!setAlarmDone && gotCurrentTime)
  {
    setAlarm();
  }

  if (alarmTriggered)
  {
    alarmTriggered = false;
    rtc_get_datetime(&currTime);
    datetime_to_str(datetime_buf, sizeof(datetime_buf), &currTime);
    Serial.print("Alarm @ "); Serial.println(datetime_buf);
  }
}
