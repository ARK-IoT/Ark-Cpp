#if (defined PLATFORMIO && defined UNIT_TEST)
#include <Arduino.h>

#include <AUnit.h>
#include <NTPClient.h>

#include <sys/time.h>                   // struct timeval

#if (defined ESP8266 || defined ESP32)

#ifdef ESP8266

#include <ESP8266WiFi.h>

#else

#include <WiFi.h>

#endif // ESP8266

#include <WiFiUdp.h>

namespace
{

char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password

WiFiUDP wifiUdp;
NTPClient timeClient(wifiUdp);

#define TZ              1       // (utc+) TZ in hours
#define DST_MN          60      // use 60mn for summer time in some countries

#define TZ_MN           ((TZ)*60)
#define TZ_SEC          ((TZ)*3600)
#define DST_SEC         ((DST_MN)*60)

void initNTP() {
  // Start NTP listener
  timeClient.begin();
  // Set timezone (UTC)
  timeClient.setTimeOffset(0);
  // Force update of time from NTP server
  timeClient.forceUpdate();
}

void setup_network()
{
	Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
        would try to act as both a client and an access-point and could cause
        network-issues with your other WiFi-devices on your WiFi-network. */
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

}

#else

namespace
{
void setup_network() {}
}

#endif

void setup() {
    Serial.begin(115200);
	while (!Serial); // for the Arduino Leonardo/Micro only
	delay(100);
	setup_network();
	timeClient.begin();
	aunit::TestRunner::setTimeout(0);
	delay(1000);

    // set the system clock
	timeClient.update();
	timeval tv = { static_cast<time_t>(timeClient.getEpochTime()), 0 };
	timezone tz = { TZ_MN + DST_MN, 0 };
	settimeofday(&tv, &tz);

	delay(500);

	// Examples to turn on specific tests for debugging
	//aunit::TestRunner::exclude("*");
	//aunit::TestRunner::include("api_test_peer_post_transaction");
	//aunit::TestRunner::include("utilities_slots_begin_epoch_time");
	//aunit::TestRunner::include("utilities_slots_get_real_time");
	//aunit::TestRunner::include("utilities_slots_get_time");
	//aunit::TestRunner::include("utilities_transactionToJson");
}

void loop() {
    timeClient.update();
	aunit::TestRunner::run();
}

#endif
