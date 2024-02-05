/**
 * ringBuffer.c
 *
 * Author: Desmond Stular
 *   Date: February 4, 2024
 */

#include "ringBuffer.h"

/*
 * Initializes a new 10 byte ring buffer.
 */
struct ringBuffer* initBuffer() {
    struct ringBuffer *buff = malloc(sizeof(struct ringBuffer));
    buff->start = malloc(sizeof(struct node));
    buff->end = buff->start;
    struct node *ptr = buff->start;
    for (int i = 0; i < 9; i++) {
        ptr->ch = 0;
        ptr->next = malloc(sizeof(struct node));
        ptr = ptr->next;
    }
    ptr->next = buff->start;
    buff->size = 0;
    return buff;
}

/*
 * Creates a new node inside the ring buffer. Appends to
 * the next node after current end. Returns zero integer
 * if character could not be added and one integer if
 * successfully added.
 */
int addChar(struct ringBuffer *buff, int8_t ch) {
    // If buffer already full, return 0
    if (buff->size == 10) {
        return 0;
    }
        // If empty buffer
    else if (buff->size == 0) {
        buff->start->ch = ch;
    }
        // not an empty buffer
    else {
        buff->end = buff->end->next;
        buff->end->ch = ch;
    }
    buff->size++;
    return 1;
}

/*
 * Copies the character stored inside the start node of the
 * buffer to the destination parameter then clears char in
 * node to zero and shifts start to next node. If buffer
 * empty, assigns -1 to dest.
 */
int8_t shiftBuffer(struct ringBuffer *buff) {
    // If buff empty, copy NULL ptr to destination
    if (buff->size == 0) {
        return -1;
    }

    int value = buff->start->ch;
    buff->start->ch = 0;
    buff->size --;
    // if buffer not empty, shift start ptr
    if (buff->size != 0) {
        buff->start = buff->start->next;
    }
    return value;
}

/*
 * Frees each node that was allocated before calling free
 * on the entire buffer.
 */
void destroyBuffer(struct ringBuffer *buff) {
    struct node *temp;
    for (int i = 0; i < 10; i++) {
        temp = buff->start;
        buff->start = buff->start->next;
        free(temp);
    }
    free(buff);
}