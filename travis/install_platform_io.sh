# install PlatformIO
sudo pip install -U platformio
# update PlatformIO
platformio update

# install ArduinoJson (64), HttpClient (66), ArduinoUnit (946) libraries
platformio lib -g install 64 66 946@2.2
