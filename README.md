# sim_racing_buttonbox
Sim racing button box with rotary encoder

Needed Hardware:
- Adafruit Pro Trinket 5V 16 MHz
- 2 Luxorpart rotary encoders (https://www.amazon.com/KY-040-Encoder-Development-Arduino-Rotation/dp/B01GJS59SE)

Needed Arduino Library:
https://learn.adafruit.com/pro-trinket-keyboard/library

Guide
To connect the left encoder:
- Connect the CLK (A) to pin 9
- Connect the DT (B) to pin 10
- Connect the SW (button) to pin 4
- Connect power (5V) and GND

To connect the right encoder:
- Connect the CLK (A) to pin 12
- Connect the DT (B) to pin 11
- Connect the SW (button) to pin 3
- Connect power (5V) and GND

Useful external guides:
http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/keyes-ky-040-arduino-rotary-encoder-user-manual/
https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
