#include <stdlib.h>
#include <string.h>

#include "queue.h"

queue *queue_init(int size, int esize)
{
	queue *q;

	/* 利用不完全填满数组的技巧区分队列满与队列空 */
	size++;
	if ((q = (queue *) malloc(sizeof(queue) + size * esize)) == NULL) {
		return NULL;
	}

	q->size = size;
	q->esize = esize;
	q->rear = q->front = 0;

	return q;
}

int queue_destory(queue * q)
{
	free(q);

	return 0;
}

int queue_in(queue * q, void *element)
{
	if (queue_is_full(q)) {
		return -1;
	}

	memcpy(q->buf + q->rear * q->esize, element, q->esize);
	q->rear = (q->rear + 1) % q->size;

	return 0;
}

int queue_out(queue * q, void *element)
{
	if (queue_is_empty(q)) {
		return -1;
	}

	memcpy(element, q->buf + q->front * q->esize, q->esize);
	q->front = (q->front + 1) % q->size;

	return 0;
}

int queue_size(queue * q)
{
	return (q->rear - q->front + q->size) % q->size;
}

int queue_is_empty(queue * q)
{
	return q->rear == q->front;
}

int queue_is_full(queue * q)
{
	return (q->rear + 1) % q->size == q->front;
}
