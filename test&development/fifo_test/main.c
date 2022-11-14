#include "FIFO.h"

#define size 5


int main(void)
{
    element_type buf[size];
    element_type temp;
    FIFO_buff_t uart_fifo;

    if((FIFO_init(&uart_fifo,buf,size)==FIFO_no_error))
    {
        printf("FIFO init no error \n");
         fflush(stdout);
    }
    else
    {
        printf("FIFO init null\n");
    }
    for(int i = 0; i < size; i++)
    {
        if((FIFO_write(&uart_fifo,i)==FIFO_no_error))
        {
            printf("fifo write %d successed.\n",i);
            fflush(stdout);
        }else{
            printf("fifo write %d failed \n",i);
            fflush(stdout);
        }
    }
    /*
    FIFO_print(uart_fifo);
    if((FIFO_read(uart_fifo,&temp)==FIFO_no_error))
    {
        printf("fifo read of %d successed \n",temp);
        fflush(stdout);
    }
    if((FIFO_read(uart_fifo,&temp)==FIFO_no_error))
    {
        printf("fifo read of %d successed \n",temp);
        fflush(stdout);
    }
    FIFO_print(uart_fifo);
    */
   return 0;
}