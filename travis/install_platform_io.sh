# install PlatformIO
sudo pip install -U --trusted-host https://pypi.python.org/ platformio
# update PlatformIO
platformio update

# install ArduinoJson (64), HttpClient (66), AUnit (2778) libraries
platformio lib -g install 64 66 2778
