CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra 

STACK = stack.c stack_test.c stack.h

DEBUG = yes




stack: $(OBJECTS)
	@$(CC) $(CFLAGS) $(STACK) -o stack.out
	
make.o_stack: $(OBJECTS)
	@$(CC) $(CFLAGS) $(STACK) -c 
	
clean_stack: 
	@rm *.out *.o
	
all_stack: debug make.o make
	
debug_stack: $(OBJECTS)
	@$(CC) $(CFLAGS) $(STACK) -DDEBUG -g -o stack_debug.out 
	
release_stack: $(OBJECTS)
	@$(CC) $(CFLAGS) $(STACK) -O3 -o stack_release.out 



