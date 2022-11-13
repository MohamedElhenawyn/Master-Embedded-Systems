#include "LIFO.h"
LIFO_status LIFO_init(LIFO_Buf_t * lifo,element_type * buf , uint32_t length)
{
    if(buf != NULL)
    {
        lifo->base = buf;
        lifo->head = buf;
        lifo->length = length;
        lifo->count = 0;
        return LIFO_no_error;
    }else{
        return LIFO_null;
    }
}
LIFO_status LIFO_push(LIFO_Buf_t * lifo ,element_type item)
{
    //check if the buf is exist
    if(lifo->base)
    {
        //check the buf is not full
        if(lifo->count <= lifo->length)
        {
            *(lifo->head) = item;
            lifo->head++;
            lifo->count++;
            return LIFO_no_error;
        }
        else
        {
            return LIFO_full;
        }
        //push the item to the buf 
    }
    else
    {
        return LIFO_null;
    }
        
}
LIFO_status LIFO_pop(LIFO_Buf_t * lifo,element_type * item)
{
    if(lifo->base)
    {
        //check if the buf is empty
        if(lifo->count == 0)
        {
            return LIFO_empty;
        }else{
            lifo->head--;
            *item = *(lifo->head);
            
            lifo->count--;
            return LIFO_no_error;
        }
    }
    else
    {   
        return LIFO_null;
    }
}
void LIFO_print(LIFO_Buf_t * lifo)
{

    if(lifo->head)
    {
        if(lifo->count == 0)
        {
            printf("LIFO is empty\n");
        }
        else
        {
            element_type * tmp = (lifo->head);
            tmp--;
            for (int i =0; i < lifo->count ;i++)
            {
                printf("%d element of the lifo is %d\n", i + 1, *(tmp));
                tmp--;
            }
        }
    }
    else
    {
        printf("LIFO NULL\n");
    }
}