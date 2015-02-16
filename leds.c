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
    //Enable the ODCs for the LEDs
    ODCAbits.ODA0 = 1;  //ODC for pin 2
    ODCAbits.ODA1 = 1;  //ODC for pin 3
//Initialize the LEDs
    STOP_LED = OFF;
    RUN_LED = ON;
}

void initSW2()
{
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.

    //Put the overall CN Interrupt flag down (set it to 0)
    IFS1bits.CNIF = 0;

    TRISBbits.TRISB2 = 1; //Sets the pin for external switch to input
    AD1PCFGbits.PCFG4 = DIGITAL;    //Set the analog pin to digital

    //Enable the overall change notification interrupt
    IEC1bits.CNIE = 1;
    CNEN1bits.CN6IE = 1;
//Enable the pull up resistors for the external components
    CNPU1bits.CN6PUE = 1;   //Pull up resistor for external switch

}
void TurnOnLED(int led)
{
    if( led == STOP)
    {
    RUN_LED = OFF;  //Illuminates STOP LED
    STOP_LED = ON;
    }
    else if( led == RUN) 
    {
    RUN_LED = ON;  //Illuminates RUN LED
    STOP_LED = OFF;
    }
}