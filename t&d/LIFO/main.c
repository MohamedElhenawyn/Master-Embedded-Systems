#include "LIFO.h"
#define size 5
LIFO_elementType uart_lifo[size];

int main(void)
{
    LIFO_buff_t lifo_constructor;
    LIFO_elementType temp;
    if((LIFO_init(&lifo_constructor,uart_lifo,size))==LIFO_no_error)
    {
        printf("Uart_LIFO initialized with no errors\n");
    }else{
        printf("there is an error in constructing the lifo\n");
    }
    for(int i = 0;i < size ;i++)
    {
        if((LIFo_Push_item(&lifo_constructor,i))==LIFO_no_error)
        {
            printf("The item %d has been pushed successfully to the lifo\n",i);
        }else{
            printf("lifo pushing error\n");
        }
    }
    if((LIFO_Pop_item(&lifo_constructor,&temp))==LIFO_no_error)
    {
        printf("The item poped is %d\n",temp);
    }
    if((LIFO_Pop_item(&lifo_constructor,&temp))==LIFO_no_error)
    {
        printf("The item poped is %d\n",temp);
    }


    return 0;
}