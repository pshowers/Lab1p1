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
#include "timer.c"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

typedef enum stateTypeEnum
{
    //TODO: Define states by name
    run,
    stop
} stateType;


volatile stateType CurrState = 0;

// ******************************************************************************************* //

int main(void)
{
    CurrState = run;

    while(1)
    {
        //TODO: Using a finite-state machine, define the behavior of the LEDs
        //Debounce the switch
        switch(CurrState)
        {
            case run:
            TurnOnLED(RUN);
            break;

            case stop:
            TurnOnLED(STOP);
            break;
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
            CurrState = stop;
        }
        else if(CurrState == stop)
        {
            CurrState = run;
        }
    }

}
