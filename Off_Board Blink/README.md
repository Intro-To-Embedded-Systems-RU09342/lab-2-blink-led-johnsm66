# Off Board Blink
The code for off board blink is very similar to that of multiple blink. The difference is that instead of the ouput 
pins being the onboard LEDs, the output pins are set to ones on the G2553 chip. Do to the removable chip, Off board 
blink is specific to 
* MSP430G2553


## Connections to chip
- Power to VCC pin
- Ground to VSS pin
- two output pins to two LEDS
- Power must also go to reset pin 

##  Implementation
The code must first be run with the chip on the MSP430G24553. Once the program is ran, the chip is then programmed 
and can be removed. The chip should then be placed onto a breadboard where the propper connections can be wired. 
Once wired completely and given power, the LEDs should blink like the multiple blink code.  