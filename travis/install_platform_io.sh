# install PlatformIO
sudo pip install -U platformio

# update PlatformIO
platformio update

# install ArduinoJson (64), AUnit (2778), NTPClient (551) libraries
platformio lib -g install 64 2778 551
