/* 
* File:   leds.h
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef LEDS_H
#define	LEDS_H

/*****************************************************************
 * Defines the LEDs based on their latch pin numbers
*****************************************************************/
#define STOP_LED LATAbits.LATA0
#define RUN_LED LATBbits.LATA1
#define STOP 0
#define RUN 1
#define RELEASED 1
#define PRESSED 0
/****************************************************************/

/*****************************************************************
 * Defines when the LEDs are turned ON or OFF
*****************************************************************/
#define OFF 1;
#define ON 0;
/*****************************************************************/
#define DIGITAL 1;
#define ANALOG 0;

void initLEDs();
void initSW2();
void TurnOnLED(int led);

#endif	/* LEDS_H */

