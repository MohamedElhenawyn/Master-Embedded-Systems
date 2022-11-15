#include "FIFO.h"
FIFO_status FIFO_init(FIFO_buff_t * fifo,element_type * buf, uint32_t length)
{
    if(buf)
    {
        fifo->head = buf;
        fifo->base = buf;
        fifo->tail = buf;
        fifo->length = length;
        fifo->count = 0;
        return FIFO_no_error;
    }else{
        return FIFO_null;
    }
}
FIFO_status FIFO_write(FIFO_buff_t *fifo,element_type item)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
    {
        return FIFO_null;
    }
    else
    {
        if((FIFO_is_full(fifo)==FIFO_no_error))
        {
            if((fifo->head) == (fifo->base + (fifo->length *sizeof(element_type))))
            {
                *(fifo->head) = item;
                fifo->head = fifo->base;
                fifo->count++;
            }else
            {
                *(fifo->head) = item;
                fifo->head++;
                fifo->count++;
            }

        }
    }
    return FIFO_no_error;
}

FIFO_status FIFO_is_full(FIFO_buff_t *fifo)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
    {
        return FIFO_null;
    }
    else
    {
        if(fifo->count == fifo->length)
        {
            return FIFO_full;
        }else
        {
            return FIFO_no_error;
        }
    }
}