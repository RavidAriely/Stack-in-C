#include "stack.h"
#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */
#include <string.h> /* string */

/*
 * Struct:  stack 
 * --------------------
 *   top:           pointer to top of the stack 
 *   base:	     pointer to base of the stack
 *   capacity:      maximum number of elements the stack can hold
 *   element_size:  size of each element
 */
struct stack
{
	void *top;                                                
	void *base;                                           
	size_t capacity;
	size_t element_size;
};

/* Function:  StackCreate 
 * --------------------
 *   creates a new stack with a specified capacity and element size
 *
 *   capacity:  maximum number of elements the stack can hold
 *   elem_size: size of each element 
 *
 *   returns: pointer to the newly created stack
 */
stack_t *StackCreate(const size_t capacity,const size_t elem_size)
{
	stack_t *new_stack = NULL;           
	
	if(0 == capacity || 0 == elem_size)
	{
		return NULL;
	}
	
	new_stack = malloc(sizeof(stack_t));
	if(NULL == new_stack)
	{
		return NULL;
	}
	
	new_stack -> base = malloc(elem_size * capacity);        
	if(NULL == new_stack -> base)
	{
		free(new_stack);
		return NULL;
	}
	
	new_stack -> capacity = capacity;
	new_stack -> element_size = elem_size;
	new_stack -> top = new_stack -> base;                  
	
	return new_stack;
}

/* Function:  StackDestroy 
 * --------------------
 *   deallocates the memory used by the stack
 *
 *   stack: pointer to the stack
 *
 *   returns: no return value
 */
void StackDestroy(stack_t *stack)
{
	assert(stack);
	
	free(stack -> base);
	free(stack);
}

/* Function:  StackPeek 
 * --------------------
 *   stack: pointer to the stack 
 *
 *   returns: pointer to the top element of the stack
 */
void *StackPeek(const stack_t *stack)
{
	assert(stack);
	return (char*)stack -> top - stack -> element_size;
}

/* Function:  IsStackEmpty 
 * --------------------
 *   checks if the stack is empty
 *
 *   stack: pointer to the stack
 *
 *   returns: 1 for full stack or 0 if stack is empty
 */
int IsStackEmpty(const stack_t *stack)
{
	assert(stack);
	
	if(stack -> top > stack -> base)
	{
		return 1;
	}
	
	return 0;                                             
}

/* Function:  StackPop 
 * --------------------
 *   removes the top element from the stack
 *
 *   stack: pointer to the stack
 *
 *   returns: 0 for success, -1 for failure
 */
int StackPop(stack_t *stack)
{
	assert(stack);
	
	if(0 == IsStackEmpty(stack))
	{
		return -1;
	}
	
	stack -> top = (char*)stack -> top - stack -> element_size;
	
	return 0;
}

/* Function:  StackSize 
 * --------------------
 *   stack: pointer to the stack
 *
 *   returns: number of elements in the stack
 */
size_t StackSize(const stack_t *stack)                        
{
	assert(stack);
	
	return ((char*)stack -> top - (char*)stack -> base) / stack -> element_size;
}

/* Function:  StackCapacity 
 * --------------------
 *   stack: pointer to the stack
 *
 *   returns: maximum number of elements the stack can hold
 */
size_t StackCapacity(const stack_t *stack)                       
{	
	assert(stack);
	
	return stack -> capacity;
}

/* Function:  StackPush 
 * --------------------
 *   pushes a new element onto the top of the stack
 *
 *   stack: pointer to the stack 
 *   elem:  pointer to the element to be pushed
 *
 *   returns: 0 for success, -1 for failure
 */
int StackPush(stack_t *stack ,const void *elem)
{
	assert(stack);
	assert(elem);
	
	if(0 == (StackCapacity(stack) - StackSize(stack)))
	{
		return -1;
	}
	
	memcpy(stack -> top, elem, stack -> element_size);
	stack -> top = (char*)stack -> top + stack -> element_size;
	
	return 0;
}
