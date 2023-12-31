#ifndef STACK_H
#define STACK_H

#include <stddef.h> /* size_t */
#include <stdio.h>  /* print  */

typedef struct stack stack_t;

/* creates a new stack with a specified capacity and element size */
stack_t *StackCreate(const size_t capacity,const size_t elem_size);

/* deallocates the memory used by the stack */
void StackDestroy(stack_t *stack);

/* pushes a new element onto the top of the stack */
int StackPush(stack_t *stack ,const void *elem);

/* return the top element of the stack */
void *StackPeek(const stack_t *stack);

/* removes the top element from the stack */
int StackPop(stack_t *stack);

/* checks if the stack is empty */
int IsStackEmpty(const stack_t *stack);

/* returns the number of elements in the stack */
size_t StackSize(const stack_t *stack);

/* returns the maximum number of elements the stack can hold */
size_t StackCapacity(const stack_t *stack);

#endif  /* STACK_H */
