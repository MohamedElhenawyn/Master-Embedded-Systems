#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include <stdio.h>
#define element_type uint32_t

typedef struct
{
    uint32_t length ;
    uint32_t count;
    element_type * head ;
    element_type * base;
    element_type * tail;
}FIFO_buff_t;

typedef enum
{
    FIFO_no_error,
    FIFO_null,
    FIFO_empty,
    FIFO_full
}FIFO_status;

FIFO_status FIFO_init(FIFO_buff_t * fifo,element_type * buf, uint32_t length);
FIFO_status FIFO_write(FIFO_buff_t *fifo,element_type item);
FIFO_status FIFO_read(FIFO_buff_t * fifo,element_type *item);
FIFO_status FIFO_is_full(FIFO_buff_t *fifo);
void FIFO_print(FIFO_buff_t * fifo);

#endif
