#include "LIFO.h"
#define size 5
element_type buf[size];
int main(void)
{
    element_type temp;
    LIFO_Buf_t * uart_lifo;

    if((LIFO_init(uart_lifo,buf,size) == LIFO_no_error))
    {
        printf("LIFO init successed \n");
    }
    else
    {
        printf("There is a  problem in initializing the lifo \n");
    }
    for(int i = 0 ; i < size; i++)
    {
        if((LIFO_push(uart_lifo,i)== LIFO_no_error))
        {
            printf("Item %d pushed to the lifo \n",i);
        }else
        {
            printf("There is a problem in pushing %d element to the lifo\n",i);
        }
    }
    LIFO_print(uart_lifo);
    if((LIFO_pop(uart_lifo,&temp) == LIFO_no_error))
    {
        printf("Poping %d successed\n",temp);
    }
    if((LIFO_pop(uart_lifo,&temp) == LIFO_no_error))
    {
        printf("Poping %d successed\n",temp);
    }
    LIFO_print(uart_lifo);

    return 0;
}