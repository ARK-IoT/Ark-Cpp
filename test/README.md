



# PlatformIO

### dependencies

**Python:**  
Use an installer package from the following link:  
```https://www.python.org/downloads/```

#

**PlatformIO:**  
install PlatformIO if not already installed  
```pip install -U platformio```  
or  
```python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"```

also install platformio dependencies:  
> install ArduinoJson (64), HttpClient (66), AUnit (2778) libraries  
```platformio lib -g install 64 66 2778```

#  

### provide your WiFi info for your board to access the internet   

**open the following file in your preferred code editor:**  

> "*.../Ark-Cpp/test/IoT/test_main.cpp*"  


lines 19 & 20:  
```
char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password
```

#

### running the tests on an ESP8266 board

**`cd` into this directory "*.../Ark-Cpp/test*"**  
> ```cd test```

**execute the following command to upload test to your board**  
> pio run -e nodemcuv2 -t upload

#

### what you should see from your serial monitor

```
WiFi connected
IP address:
xxx.xxx.x.xx
TestRunner started on 38 test(s).
Test api__test_account passed.
Test api__test_account_balance passed.
Test api__test_account_delegates passed.
Test api__test_account_delegates_fee passed.
Test api__test_account_public_key passed.
Test api__test_block passed.
Test api__test_block_epoch passed.
Test api__test_block_fee passed.
Test api__test_block_fees passed.
Test api__test_block_height passed.
Test api__test_block_milestone passed.
Test api__test_block_net_hash passed.
Test api__test_block_reward passed.
Test api__test_block_status passed.
Test api__test_block_supply passed.
Test api__test_delegate_fee passed.
Test api__test_delegate_forged_by_account passed.
Test api__test_delegate_pub_key passed.
Test api__test_delegate_user passed.
Test api__test_delegates_count passed.
Test api__test_loader passed.
Test api__test_peer passed.
Test api__test_signature passed.
Test api__test_transaction passed.
Test model__construct_account passed.
Test model__construct_block passed.
Test model__construct_currency passed.
Test model__construct_delegate passed.
Test model__construct_fees passed.
Test model__construct_network passed.
Test model__construct_peer passed.
Test model__construct_transaction passed.
Test model__construct_voter passed.
Test types__construct_address passed.
Test types__construct_balance passed.
Test types__construct_hash passed.
Test types__construct_publickey passed.
Test types__construct_signature passed.
TestRunner summary: 38 passed, 0 failed, 0 skipped, 0 timed out, out of 38 test(s).
```
😎👍
