#ifndef __STACK_H__
#define __STACK_H__

typedef struct {
	int size;
	int esize;
	void *top;
	unsigned char buf[0];
} stack;

stack *stack_init(int size, int esize);
int stack_destory(stack * s);

int stack_push(stack *s, void *element);
int stack_pop(stack *s, void *element);
int stack_top(stack *s, void *element);

int stack_is_empty(stack *s);
int stack_is_full(stack *s);

#endif
