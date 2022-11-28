#include "main.h"
#include "sEos.h"
#include "xc.h"

tLong preloadValue;
void sEos_Init_Timer1(const tByte TICK_MS)
{
    TMR1 = 15535;
    /*
     * Tout = (4*prescalar*(65536-TMR1)*X/Fosc
     * X is the number of overFlows
     */
    //preloadValue = (5242880-(TICK_MS * 4000000)) / 80;
    
    //TMR1 =  preloadValue;
    // Choose the local clock source (timer mode)
    TMR1CS = 0;
    // Choose the desired prescaler ratio (1:1)
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    // Event1 = LED ON
    RB0 = 1;
    // Switch ON Timer1 Module!
    TMR1ON = 1;
    
    // -- [[ Interrupts Configurations ]] --
    TMR1IE = 1; // Timer1 Interrupt Enable Bit
    TMR1IF = 0; // Clear The Interrupt Flag Bit
    PEIE = 1;   // Peripherals Interrupts Enable Bit
    GIE = 1;    // Global Interrupts Enable Bit
}
