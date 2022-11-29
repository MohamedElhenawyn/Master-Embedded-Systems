#include "FIFO.h"

FIFO_status FIFO_init(FIFO_buff_t * lBuf,element_type * buff,uint32_t length)
{
    if(buff == NULL)
    {
        return FIFO_null;
    }
    //init the fifo 
    lBuf->base = buff;
    lBuf->head = buff;
    lBuf->tail = buff;
    lBuf->length = length;
    lBuf->count = 0;    
    return FIFO_no_error;
}
FIFO_status FIFO_push(FIFO_buff_t * lBuf,element_type item)
{
    if(!lBuf->base)
    {
        return FIFO_null;
    }
    if(lBuf->count == lBuf->length)
    {
        return FIFO_full;
    }
    if(lBuf->head == (lBuf->base + (sizeof(element_type)*lBuf->length)))
    {
        *lBuf->head = item;
        lBuf->count++;
        lBuf->head = lBuf->base; 
    }
    else
    {
        *lBuf->head = item;
        lBuf->count++;
        lBuf->head++;
    }
    return FIFO_no_error;
}
FIFO_status FIFO_pop(FIFO_buff_t * lBuf , element_type * item)
{
    if(!lBuf->base)
    {
        return FIFO_null;
    }
    if(lBuf->count == 0)
    {
        return FIFO_empty;
    }
    if(lBuf->tail == (lBuf->base + (sizeof(element_type)*lBuf->length)))
    {
        *item = *lBuf->tail;
        lBuf->count--;
        lBuf->tail = lBuf->base;
    }else{
        *item = *lBuf->tail;
        lBuf->count--;
        lBuf->tail++;
    }
    return FIFO_no_error;
}

FIFO_status print_FIFO(FIFO_buff_t * lBuf)
{
    element_type * temp ;
    temp = lBuf->tail;
    if(!lBuf->base)
    {
        return FIFO_null;
    }
    if(lBuf->count == 0)
    {
        return FIFO_empty;
    }
    printf("The Buffer has %d elemnts.\n",lBuf->count);
    for(uint32_t i = 0; i < lBuf->count;i++)
    {
        if(temp == (lBuf->base + (sizeof(element_type)*lBuf->length)))
        {
            printf("%d- element is %d\n",i + 1,*temp);
            temp = lBuf->base;
        }else
        {
            printf("%d- element is %d\n",i + 1,*temp);
            temp++;
        }
    } 
    return FIFO_no_error;        
}