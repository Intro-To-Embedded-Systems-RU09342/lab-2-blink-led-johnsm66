## Multiple Blink
Multiple blink is also very similar to simple blink. The difference is that the pins for two LED are enable rather 
than just one. Also, the two LEDs are to be set at two different rates. The microprocessors used were, 
* MSP430G2553
* MSP430FR6989

## Code
The libary, #include <msp430.h>, must be included for the MSP430 library to function. To toggle on an LED on, 
the pin corresponding to the LED desired is XORed wtih a 1. To have multiple blink, there must be a simple loop 
just as the code for simple blink. Except for multiple blink, two LEDs are toggled within the loop. There is also
multiple delays within the loop to cause the LEDs to toggle at different rates.Below is general code for a multiple 
blink.

```
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT0;                          // Set P1.0 to output direction
    P1DIR |= BIT6;                          // Clear P1.6 output latch for a defined power-on state
    P1OUT |= BIT6;                          // Set P1.6 to output direction



    while(1)
    {
        P1OUT ^= BIT0;                   //Toggle LED
        P1OUT ^= BIT6;                   // Toggle LED
        __delay_cycles(100000);
        P1OUT ^= BIT0;                   // Toggle LED
        __delay_cycles(100000);
    }
}
```
