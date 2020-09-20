#include <stdio.h>

#include "queue.h"

#define QUEUE_SIZE 3

char *char_dump(char *element);

int main(int argc, char **argv)
{
	queue *q;

	int ret;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char element;

	if ((q = queue_init(QUEUE_SIZE, sizeof(char))) == NULL) {
		return -1;
	}

	ret = queue_in(q, &a);
	printf("1. %d\n", ret);

	ret = queue_in(q, &b);
	printf("2. %d\n", ret);

	ret = queue_in(q, &c);
	printf("3. %d\n", ret);

	// 测试队列满
	ret = queue_in(q, &d);
	printf("4. %d\n", ret);

	ret = queue_out(q, &element);
	printf("5. %d %c\n", ret, element);

	ret = queue_out(q, &element);
	printf("6. %d %c\n", ret, element);

	ret = queue_out(q, &element);
	printf("7. %d %c\n", ret, element);

	// 测试队列空
	ret = queue_out(q, &element);
	printf("8. %d\n", ret);

	queue_destory(q);

	return 0;
}

char *char_dump(char *element)
{
	printf("%c\n", *element);
}
