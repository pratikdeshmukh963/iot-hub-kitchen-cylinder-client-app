### iot-hub-kitchen-cylinder-client-app

**How to do setup for Arduino so that it can be used with Microsoft SDK**
- Follow these steps mentioned here https://github.com/Azure/azure-iot-arduino
- From the above steps just modify platform.local.txt to be similar to platform.txt. Or you can simply not copy platform.local.txt and just directly do modifications in platform.txt.
- Install latest version of python.
- In platform.txt file (or if you are using platform.local.txt use that) replace {runtime.tools.python.path}/python with {runtime.tools.python3.path}/python3. At the time of installation python3 was present it might change for other version of python.

***Code Referene***: https://github.com/Azure/azure-iot-device-ecosystem/blob/master/get_started/iot-hub-arduino-huzzah-esp8266-get-started.md  
***Setup Arduino in VS code***: https://cuneyt.aliustaoglu.biz/en/enabling-arduino-intellisense-with-visual-studio-code/  
***Weight sensor device hookup diagram***: https://circuitjournal.com/50kg-load-cells-with-HX711
