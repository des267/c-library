#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <stdlib.h>
#include <stdint.h>

struct node {
    struct node *next;
    int8_t ch;
};

struct ringBuffer {
    struct node *start;
    struct node *end;
    int size;
};

struct ringBuffer* initBuffer();
int addChar(struct ringBuffer *buff, int8_t ch);
int8_t shiftBuffer(struct ringBuffer *buff);
void destroyBuffer(struct ringBuffer *buff);

#endif