#include <msp430.h>
//Michael Johns
//MSP430G2553
//Off-Board blink
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P2DIR |= BIT2;                          // Clear P2.2 output latch for a defined power-on state
    P2OUT |= BIT2;                          // Set P2.2 to output direction
    P2DIR |= BIT3;                          // Clear P2.3 output latch for a defined power-on state
    P2OUT |= BIT3;                          // Set P2.3 to output direction



    while(1)
    {
        P2OUT ^= BIT2;                   //Toggle P2.2 on
        P2OUT ^= BIT3;                   //Toggle P2.3 on
        __delay_cycles(100000);          //set delay for output
        P2OUT ^= BIT2;                   //Toggle P2.2 on
        __delay_cycles(100000);          //set delay for output
    }



}
