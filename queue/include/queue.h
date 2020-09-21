#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct {
	int size; // 容量
	int esize; // 元素大小
	int front; // 指向下一个可读的位置
	int rear; // 指向下一个可写的位置
	unsigned char buf[];
} queue;

queue *queue_init(int size, int esize);
int queue_destroy(queue * q);
int queue_in(queue *q, void *element);
int queue_out(queue *q, void *element);
int queue_size(queue *q);
int queue_is_empty(queue *q);
int queue_is_full(queue *q);

#endif
