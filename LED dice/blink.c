#include <msp430.h>
#include <MSP430F5529.h>
#define BUTTON BIT1
/**
 * blink.c
 */
//define globals
        volatile unsigned int i;
        volatile unsigned int j=0x07;// volatile to prevent optimization
     //   j=0x07;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
        P6DIR |= 0x7F;
        P1IE |= BUTTON;
      //  P6OUT &= 0x00;

      P1REN |= BUTTON;
      P1OUT |= BUTTON;
    P1IFG &= ~BUTTON;
    __enable_interrupt();

    for(;;){
    }
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){


    //      for( j=0x07;j<=0xFF;j*=2){
    //      P6OUT = j;              // toggle P1.0
    //      for(i=1000000; i>0; i--);     // delay
    //  }
    //      for(j; j>0x00;j/=2){
    //          P6OUT= j;
    //          for(i=1000000; i>0; i--);
    //      }
  //
  //P6OUT=0xFF;
    srand(time(0));
    switch(rand()%6+1){
        case 1:
            P6OUT=0x04;
            break;
        case 2:
            P6OUT=0x30;
            break;
        case 3:
            P6OUT=0x34;
            break;
        case 4:
            P6OUT=0x72;
            break;
        case 5:
            P6OUT=0x76;
            break;
        case 6:
            P6OUT=0x7B;
            break;
        default:
            printf("How the hell did you get here");
            break;
    }
       P1IFG &= ~BUTTON;




}

