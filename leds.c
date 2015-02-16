/*
* File:   leds.c
* Author: Phillip Showers
*
* Created on February 9 2015
*/

#include "p24fj64ga002.h"
#include "leds.h"

void initLEDs()
{
//TODO: Initialize the appropriate pins to work with the LEDs
    TRISAbits.TRISA0 = 0; //Sets IO1 to an output
    TRISAbits.TRISA1 = 0; //Sets IO2 to an output
//Initialize the LEDs
    STOP_LED = OFF;
    RUN_LED = OFF;
}

void initSW2()
{
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.
    TRISBbits.TRISB2 = 1; //Sets the pin for external switch to input
    AD1PCFGBITS.PCFG4 = DIGITAL;
    //Put the overall CN Interrupt flag down (set it to 0)
    IFS1bits.CNIF = 0;

    //Enable the overall change notification interrupt
    IEC1bits.CNIE = 1;

    /* Enable the change notification interrupt for the switch 1 connected to
     * the development board. This corresponds to CN27 according to the PIC24F
     * datasheet. The internal pull-up should not be used for the switch
     * on the development board because one is already there.
     */
    CNEN2bits.CN27IE = 1;
//Enable the pull up resistors for the external components
    CNPU1bits.CN2PUE = 1;
    CNPU1bits.CN3PUE = 1;
    CNPU1bits.CN6PUE = 1;

//Enable the ODCs for the LEDs
    ODCAbits.ODA0 = 1;  //ODC for pin 2
    ODCAbits.ODA0 = 1;  //ODC for pin 3
}
void TurnOnLED(int led)
{
    if( led == STOP)
    {
    RUN_LED = OFF;  //Illuminates LED4
    STOP_LED = ON;
    }
    else if( led == RUN)  //Illuminates LED5
    {
    RUN_LED = ON;  //Illuminates LED4
    STOP_LED = OFF;
    }
}