#include <msp430.h>
//Michael Johns
//MSP430G2553
//Simple Blink
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT0;                          // Set P1.0 to output direction



    while(1)
    {
        P1OUT ^= BIT0;                      //Toggle LED
        __delay_cycles(100000);             //set delay for LED

    }



}
