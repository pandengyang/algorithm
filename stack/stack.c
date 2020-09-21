#include <stdlib.h>
#include <string.h>

#include "stack.h"

stack *stack_init(int size, int esize)
{
	stack *s;

	if ((s = (stack *) malloc(sizeof(stack) + size * esize)) == NULL) {
		return NULL;
	}

	s->size = size;
	s->esize = esize;

	s->top = s->buf + size * esize;

	return s;
}

int stack_destroy(stack * s)
{
	free(s);

	return 0;
}

int stack_push(stack * s, void *element)
{
	if (stack_is_full(s)) {
		return -1;
	}

	s->top -= s->esize;
	memcpy(s->top, element, s->esize);

	return 0;
}

int stack_pop(stack * s, void *element)
{
	if (stack_is_empty(s)) {
		return -1;
	}

	memcpy(element, s->top, s->esize);
	s->top += s->esize;

	return 0;
}

int stack_top(stack * s, void *element)
{
	if (stack_is_empty(s)) {
		return -1;
	}

	memcpy(element, s->top, s->esize);

	return 0;
}

int stack_is_empty(stack * s)
{
	return s->top == (s->buf + s->size * s->esize);
}

int stack_is_full(stack * s)
{
	return s->top == s->buf;
}
