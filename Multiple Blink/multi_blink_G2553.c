#include <msp430.h>
//Michael Johns
//MSP430G2553
//Multi Blink
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
