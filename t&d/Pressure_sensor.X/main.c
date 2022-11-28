/*
 * File:   main.c
 * Author: melhenawy
 *
 * Created on 28 November 2022, 13:26
 */

#include"main.h"
#include <xc.h>
#include "config.h"
#include "sEos.h"
#include <stdio.h>
uint8_t C;
extern tLong preloadValue;


void main(void) {
    TRISB0 = 0;
    RB0 = 0;
    sEos_Init_Timer1(20);
    while(1)
    {
    }
    return;
}

void __interrupt() ISR()
{
    if (TMR1IF)
   {
      C++;
      if(C==20)  // Note that we're counting up to 20 timer overflows!
      {
        // Event2 = (e.g. Toggle LED, Stop perupheral, Take ADC reading, etc)
        RB0 = ~RB0;
        // Clear The Global Counter
        C = 0;
      }
      // Preload The Value To TMR1 Register Every Overflow Interrupt
      //TMR1 = (unsigned short)preloadValue;
      TMR1 = 15535; 
      TMR1IF = 0; // Clear The Flag Bit
   }
}