# download any additional supported boards
arduino --pref "boardsmanager.additional.urls=http://arduino.esp8266.com/stable/package_esp8266com_index.json" --save-prefs

# install supported boards
arduino --install-boards esp8266:esp8266
