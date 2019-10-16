## Button Blink
Button is very similar to simple blink. The difference is that the condition if the a button is pressed is used to 
toggle the LED on. The microprocessors used were, 
* MSP430G2553
* MSP430FR6989

## Code
The libary, #include <msp430.h>, must be included for the MSP430 library to function. To toggle on an LED on, 
the pin corresponding to the LED desired is XORed wtih a 1. To toggle of an LED, the corresponding pin is ANDed. To 
have a button blink, there must be a simple loop that must check if the button is being pressed. If button is 
pressed the toggle LED on, if not pressed then toggle LED off.Below is general code for a button blink.

```
#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer similia 
	
	volatile int i;         //integer value from internal counter


	        P1DIR = 0x01;       //sets bit 0 of P1 as the output
	        P1OUT = BIT3;     //Clears bit 3 of P1 which is the button
	        P1REN = BIT3;       //Enables Pullup resistor on pin 1.3

	        for (;;){   //Initializes an empty loop

	             if((~P1IN&BIT3))    //If the Button (P1.3) is Pressed, allows the LED to toggle
	                    P1OUT ^= 0x01; //Toggles bit 0 on P1 by XORing bit 0 with itself

	                    i = 8000;         //
	                    do i--;           // Initiates a delay between toggling bit 0
	                    while (i != 0);   //

	        }
}
```
