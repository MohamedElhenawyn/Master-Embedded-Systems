#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define element_type uint32_t
typedef struct 
{   
    uint32_t length;
    uint32_t count;
    element_type * head; //the pointer used to push items
    element_type * base;//the address of the base of the fifo
    element_type * tail;//the pointer used to pop items from the fifo
}FIFO_buff_t;

typedef enum{
    FIFO_no_error,
    FIFO_null,
    FIFO_full,
    FIFO_empty
}FIFO_status;

FIFO_status FIFO_init(FIFO_buff_t * lBuf,element_type * buff,uint32_t length);
FIFO_status FIFO_push(FIFO_buff_t * lBuf,element_type item);
FIFO_status FIFO_pop(FIFO_buff_t * lBuf , element_type * item);

#endif