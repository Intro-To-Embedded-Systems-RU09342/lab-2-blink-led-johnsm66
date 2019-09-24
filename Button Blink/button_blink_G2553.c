#include <msp430.h>
//Michael Johns
//MSP430G2553
//Button Blink
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop WDT


    P1DIR |= BIT0; //sets pin 1.0 to an output

    P1REN |= BIT3; //enables the pull up resistor at P1.3
    P1OUT |= BIT3; //Set P1.3 to output direction

    for(;;){ //infinite loop
        if ((P1IN&BIT3)==0x00) //if button is pushed
        {
            P1OUT ^= 0x01; //turn on LED
        }
    }

}
