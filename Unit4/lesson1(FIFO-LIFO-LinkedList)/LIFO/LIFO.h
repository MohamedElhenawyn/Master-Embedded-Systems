#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define LIFO_elementType uint32_t //define here the elemnt types of the lifo
typedef struct
{
    uint32_t length;
    LIFO_elementType * base;
    LIFO_elementType * head;
    uint32_t count;
}LIFO_buff_t;

typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_not_Full,
    LIFO_empty,
    LIFO_Not_empty,
    LIFO_Null
}LIFO_Bufferstatus;
LIFO_Bufferstatus LIFO_init(LIFO_buff_t * lBuf,LIFO_elementType * buff,uint32_t length);
LIFO_Bufferstatus LIFo_Push_item(LIFO_buff_t * lBuf ,LIFO_elementType pushItem);
LIFO_Bufferstatus LIFO_Pop_item(LIFO_buff_t * lBuf,LIFO_elementType *Popitem);

#endif