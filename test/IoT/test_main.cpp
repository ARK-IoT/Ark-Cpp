#if (defined PLATFORMIO && defined UNIT_TEST)
#include <Arduino.h>

#include <AUnit.h>

#include <sys/time.h>                   // struct timeval

#if (defined ESP8266 || defined ESP32)

#ifdef ESP8266

#include <ESP8266WiFi.h>
#include <ctime>

#else

#include <WiFi.h>

#endif // ESP8266

#include <WiFiUdp.h>

namespace
{

	char ssid[] = "your_ssid";     //  your network SSID (name)
	const char password[] = "your_password";  // your network password


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

	aunit::TestRunner::setTimeout(0);
	delay(1000);
	
    configTime(0, 60 * 60, "us.pool.ntp.org", nullptr, nullptr);

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
	aunit::TestRunner::run();
}

#endif
