#include "stack.h"
#include "utilities.h"

int main()
{
	int x = 8;
	void *ptr_x = &x;
	stack_t *ptr = NULL;
	void *peek = NULL;
	
	char y[6] = {'r', 'a', 'v', 'i', 'd', '\0'};
	void *ptr_y = &y;
	

	printf("--------------------------------------------------\n");
	printf("TEST CASE 1: destroying stack right after creation");
	printf("\n--------------------------------------------------\n\n");
	
	ptr = StackCreate(4,4);
	TESTS(ptr != NULL);
	StackDestroy(ptr);
	ptr = NULL;


	printf("\n\n------------------------------------\n");
	printf("TEST CASE 2: pushing to a full stack");
	printf("\n------------------------------------\n\n");
	
	ptr = StackCreate(4,4);
	TESTS(ptr != NULL);
	
	TESTS(IsStackEmpty(ptr) == 0);
	TESTS(StackPush(ptr, ptr_x) == 0);
	TESTS(StackPush(ptr, ptr_x) == 0);
	TESTS(StackSize(ptr) == 2);
	TESTS(StackPush(ptr, ptr_x) == 0);
	TESTS(StackPush(ptr, ptr_x) == 0);
	TESTS(IsStackEmpty(ptr) == 1);
	TESTS(StackPush(ptr, ptr_x) == -1);
	TESTS(StackSize(ptr) == 4)
	peek = StackPeek(ptr);
	TESTS(8 == *(char*)peek);
	
	

	printf("\n\n----------------------------------------\n");
	printf("TEST CASE 3: popping from an empty stack");
	printf("\n----------------------------------------\n\n");
	
	TESTS(StackSize(ptr) == 4)
	TESTS(StackPop(ptr) == 0);
	TESTS(StackPop(ptr) == 0);
	TESTS(StackPop(ptr) == 0);
	TESTS(StackSize(ptr) == 1)
	TESTS(StackPop(ptr) == 0);
	TESTS(IsStackEmpty(ptr) == 0);
	TESTS(StackPush(ptr, ptr_x) == 0);
	TESTS(StackSize(ptr) == 1)
	TESTS(StackPop(ptr) == 0);
	TESTS(IsStackEmpty(ptr) == 0);
	TESTS(StackCapacity(ptr) == 4);
	TESTS(StackPop(ptr) == -1);
	
	StackDestroy(ptr);
	ptr = NULL;
	
	
	
	printf("\n\n--------------------------------------\n");
	printf("TEST CASE 4: using different data type");
	printf("\n--------------------------------------\n\n");
	
	ptr = StackCreate(2,6);
	TESTS(ptr != NULL);
	TESTS(IsStackEmpty(ptr) == 0);
	TESTS(StackPush(ptr, ptr_y) == 0);
	TESTS(StackPush(ptr, ptr_y) == 0);
	TESTS(StackSize(ptr) == 2)
	TESTS(StackPop(ptr) == 0);
	TESTS(StackPop(ptr) == 0);
	TESTS(IsStackEmpty(ptr) == 0);
	
	StackDestroy(ptr);
	ptr = NULL;
	
	return 0;
}
