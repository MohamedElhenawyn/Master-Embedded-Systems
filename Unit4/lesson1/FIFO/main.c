#include "FIFO.h"
#define size 5 
element_type uart_buff[size];
int main(void)
{
    FIFO_buff_t pUartBuff;
    uint32_t temp;
    if((FIFO_init(&pUartBuff,uart_buff,size))==FIFO_no_error)
    {
        printf("FIFO init successfully\n");
    }else{
        printf("FIFO init error\n");
    }
    for (uint32_t i = 0;i < size;i++)
    {
        if((FIFO_push(&pUartBuff,i))==FIFO_no_error)
        {
            printf("Push %d to the fifo\n",i);
        }
    }
    puts("");
    
    if((FIFO_pop(&pUartBuff,&temp))==FIFO_no_error)
    {
            printf("pop %d from the fifo\n",temp);
    }
    if((FIFO_pop(&pUartBuff,&temp))==FIFO_no_error)
    {
            printf("pop %d from the fifo\n",temp);
    }

    print_FIFO(&pUartBuff);

    if((FIFO_pop(&pUartBuff,&temp))==FIFO_no_error)
    {
            printf("pop %d from the fifo\n",temp);
    }
    print_FIFO(&pUartBuff);
    
    
    return 0;
}