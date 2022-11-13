#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>
#include <stdio.h>
#define element_type uint32_t

typedef struct{
    uint32_t length;
    uint32_t count;
    element_type * base;
    element_type * head;
}LIFO_Buf_t;

typedef enum
{
    LIFO_no_error,
    LIFO_null,
    LIFO_full,
    LIFO_empty
}LIFO_status;

LIFO_status LIFO_init(LIFO_Buf_t * lifo,element_type * buf , uint32_t length);
LIFO_status LIFO_push(LIFO_Buf_t * lifo ,element_type item);
LIFO_status LIFO_pop(LIFO_Buf_t * lifo,element_type * item);
void LIFO_print(LIFO_Buf_t * lifo);

#endif