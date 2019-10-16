## Simple Blink
One of the most basic coding exercises is to have an LED blink on the MSP430 microprocessor. The simple blink code
was written for
* MSP430G2553
* MSP430FR6989

## Code
The libary, #include <msp430.h>, must be included for the MSP430 library to function. To toggle on an LED on, 
the pin corresponding to the LED desired is XORed wtih a 1. To have a simple blink, there must be a simple loop
with a delay that XORs the LED pin with 1. Below is general code for a simple bink.


int main(void){
  	volatile int i;         //integer value from internal counter

  	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
  
  	P1SEL &= ~0x01;     //Selects P1 as general I/O
  	P1DIR = 0x01;       //Sets bit 0 of P1 as the output
  	P1OUT &= ~BIT0;     //Clears bit 0

  	for (;;){   //Initializes a continuous loop

  	    P1OUT ^= 0x01; //Toggles P1 bit 0 on and off by XORing bit 0 with a 1.

  	    i = 8000;         //
  	    do i--;           // Initiates a delay between toggling bit 0
  	    while (i != 0);   //
  	}
}
