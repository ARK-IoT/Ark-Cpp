#include "tests.h"

void setup()
{
	Serial.begin(9600);
	while (!Serial); // for the Arduino Leonardo/Micro only
}

void loop()
{
	Test::run();
}