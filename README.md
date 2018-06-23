# sim_racing_buttonbox
Sim racing button box with rotary encoder.
2 rotary encoders with push buttons connected with an arduino.
When pushing on a button or turning the knob, the arduino will mimic
a keyboard and send a ASCII charachter through USB to the connected computer.
Then change the game how these charachter should be interpreted.

Used charachter for the right encoder:
A - button press
X - right turn
Z - left turn

Used charachter for the left encoder:
S - button press
V - right turn
C - left turn

Needed Hardware:
- Adafruit Pro Trinket 5V 16 MHz
- 2 Luxorpart rotary encoders (https://www.amazon.com/KY-040-Encoder-Development-Arduino-Rotation/dp/B01GJS59SE)
- USB cable
- Wire cable 


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

Connect the USB cable and plug it into a computer.

Useful external guides:
- http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/keyes-ky-040-arduino-rotary-encoder-user-manual/
- https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
