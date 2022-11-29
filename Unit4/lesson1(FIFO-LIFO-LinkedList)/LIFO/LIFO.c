#include "LIFO.h"

LIFO_Bufferstatus LIFO_init(LIFO_buff_t * lBuf,LIFO_elementType * buff,uint32_t length)
{
    if(buff == NULL)
    {
        return LIFO_Null;
    }
    lBuf->base = buff;
    lBuf->head = buff;
    lBuf->length = length;
    lBuf->count = 0;
    return LIFO_no_error;
}
LIFO_Bufferstatus LIFo_Push_item(LIFO_buff_t * lBuf ,LIFO_elementType pushItem)
{
    if(!lBuf->head || !lBuf->base)
    {
        return LIFO_Null;
    }
    if(lBuf->count == lBuf->length)
    {
        return LIFO_full;
    }
    *(lBuf->head) = pushItem ;
    lBuf->head++;
    lBuf->count++;
    return LIFO_no_error;
}
LIFO_Bufferstatus LIFO_Pop_item(LIFO_buff_t * lBuf,LIFO_elementType *Popitem)
{
    if(!lBuf->head || !lBuf->base)
    {
        return LIFO_Null;
    }
    if(lBuf->head == lBuf->base)
    {
        return LIFO_empty;
    }
    lBuf->head--;
    lBuf->count--;
    *(Popitem) = *(lBuf->head);
    return LIFO_no_error;
}