#include <stdint.h>

void Reset_Handler(void);
extern int main(void);
void Default_Handler()
{
    Reset_Handler();
}
void NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void BusFault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void usageFault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void svCall_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void DebugMonitor_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void PendSV_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void SysTick(void) __attribute__ ((weak,alias("Default_Handler")));
void WWDG_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void PVD_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void tamper_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void RTC_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Flash_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void RCC_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void EXTl0_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void EXTl1_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void EXTl2_Handler(void) __attribute__ ((weak,alias("Default_Handler")));

static unsigned long stack_top[256];
void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = 
{
    (void(*)()) ((unsigned long)stack_top + sizeof(stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &HardFault_Handler,
    &MemManage_Handler,
    &BusFault_Handler,
    &usageFault_Handler,
    &svCall_Handler,
    &DebugMonitor_Handler,
    &PendSV_Handler,
    &SysTick,
    &WWDG_Handler,
    &PVD_Handler,
    &tamper_Handler,
    &RTC_Handler,
    &Flash_Handler,
    &RCC_Handler,
    &EXTl0_Handler,
    &EXTl1_Handler,
    &EXTl2_Handler
};

extern unsigned int _E_text_;
extern unsigned int _S_data_;
extern unsigned int _E_data_;
extern unsigned int _S_bss_;
extern unsigned int _E_bss_;

void Reset_Handler()
{
    //copy data section from flash to ram
    unsigned int DATA_size = (unsigned char * ) & _E_data_ - (unsigned char *)&_S_data_;
    unsigned char *P_src = (unsigned char *)&_E_text_;
    unsigned char *P_dst = (unsigned char *)&_S_data_;
    for (int i = 0; i < DATA_size;i++)
    {
        *((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
    }
    //initialize bss section
    unsigned int bss_size = (unsigned char *)& _E_bss_ - (unsigned char *)&_S_bss_;
    P_dst = (unsigned char *)&_S_bss_;
    for(int i = 0; i < bss_size;i++)
    {
        *((unsigned char *)P_dst++) = (unsigned char )0;
    }
    main();
}
