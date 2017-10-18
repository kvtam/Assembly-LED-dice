/*Kyle Tam
 * UAF CS 301 project
 * LED dice with an MSP430F5529LP
 * C code
 * Last Revised 10-17-2017
*/

//    LED Breadboard enumeration of 7-pip display
//
//    [P6.5]            [P6.6]
//    [P6.0]    [P6.2]  [P6.3]
//    [P6.1]            [P6.4]
//

#include <msp430.h>
#include <MSP430F5529.h>
#define BUTTON BIT1                 //  The button on the launchpad is P1.1

void main(void)
{
        srand(time(0));                //Seeded random function with time
       WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer
       P6DIR |= 0x7F;              // Set all port 6 Pins 0-6 to outputs
        P1IE |= BUTTON;             // Enable the button P1.1
       P1REN |= BUTTON;              // Enable internal pull-up resistor
       P1OUT |= BUTTON;              // Set button as an output
        
    _BIS_SR(LPM0_bits+GIE);         //Enter Low power mode 0 and open all interrupts
}

void lights(){
    switch(rand()%6+1){            //Switch on values 1-6
            case 1:
                // P6OUT=0x04;
                set_port(0x04);
                break;
            case 2:
                // P6OUT=0x30;
                set_port(0x30);
                break;
            case 3:
                // P6OUT=0x34;
                set_port(0x34);
                break;
            case 4:
                // P6OUT=0x72;
                set_port(0x72);
                break;
            case 5:
                // P6OUT=0x76;
                set_port(0x76);
                break;
            case 6:
                // P6OUT=0x7B;
                set_port(0x7B);
                break;
            default:
                break;
        }

}
#pragma vector=PORT1_VECTOR         // Set up interrupt vector
__interrupt void Port_1(void){

        lights();                   // Call the lights function from the interrupt
       P1IFG &= ~BUTTON;           // Clear interrupt flag
}

