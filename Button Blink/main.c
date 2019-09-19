#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    P1DIR = 0x01;
    P1REN |= BIT1;    //enables the pull up resistor at P1.1
    P1OUT |= BIT1;

        for(;;)
        {
            int temp = P1IN & BIT1;     //Comparator for the button to register that they have been pushed

            if(temp == 2)       //button not pressed state, LED off
            {
                P1OUT &= BIT1;
            }
            else                //button pressed state, LED flashing
            {

                P1OUT ^= 0x01;
            }
        }

}
