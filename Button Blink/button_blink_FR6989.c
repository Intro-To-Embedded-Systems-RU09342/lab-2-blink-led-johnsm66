#include <msp430.h>
//Michael Johns
//MSP430Fr6989
//Button Blink
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    // Configure GPIO
    P1DIR = 0x01;     // Clear P1.1 output latch for a defined power-on state
    P1REN |= BIT1;    //enables the pull up resistor at P1.1
    P1OUT |= BIT1;    // Set P1.1 to output direction

        for(;;)
        {
            int temp = P1IN & BIT1;     //Comparator for the button to register that they have been pushed

            if(temp == 2)       //if button not pressed, set LED to off
            {
                P1OUT &= BIT1;
            }
            else                //if button is pressed, set LED to on
            {

                P1OUT ^= 0x01;
            }
        }

}
