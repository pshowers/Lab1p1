// ******************************************************************************************* //
//
// File:         main.c
// Date:         
// Authors:      
//
// Description: Part 1 for lab 1
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "leds.h"
#include "timer.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

typedef enum stateTypeEnum
{
    //TODO: Define states by name
    run,
    stop,
    delay

} stateType;


volatile stateType CurrState = 0;
volatile stateType lastState = 0;

// ******************************************************************************************* //

int main(void)
{

    initLEDs();
    initSW2();
    CurrState = run;
    lastState = CurrState;
    
    while(1)
    {
        //TODO: Using a finite-state machine, define the behavior of the LEDs
        //Debounce the switch
        switch(CurrState)
        {
            case delay:
//            delayMs(5);
            CurrState = lastState;
            break;

            case run:
//            delayMs(5);
            TurnOnLED(RUN);
            break;

            case stop:
//            delayMs(5);
            TurnOnLED(STOP);
 
            break;
        }
    }
    
    return 0;
}

void _ISR _CNInterrupt(void)
{
    //TODO: Implement the interrupt to capture the press of the button
    IFS1bits.CNIF = 0;  //Put flag down
    if(PORTBbits.RB2 == RELEASED)
    {
        if(CurrState == run)
        {
            delayMs(5);
            CurrState = stop;
        }
        else if(CurrState == stop)
        {
            delayMs(5);
            CurrState = run;
        }
    }
    if(PORTBbits.RB2 == PRESSED)
    {
//        CurrState = delay;
        delayMs(5);
//        lastState = CurrState;
//        CurrState = delay;
    }

}

