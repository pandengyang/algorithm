#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

#define STACK_SIZE 3

typedef struct {
	char name[16];
	int age;
} student;
char *student_dump(student * s);

int main(int argc, char **argv)
{
	stack *s;

	int ret;
	student s1 = { "xiaohong", 16 };
	student s2 = { "xiaoming", 17 };
	student s3 = { "xiaoyou", 18 };
	student s1_2;
	student s2_2;
	student s3_2;

	if ((s = stack_init(STACK_SIZE, sizeof(student))) == NULL) {
		printf("stack_init error");
		return -1;
	}

	ret = stack_push(s, &s1);
	printf("1. %d\n", ret);

	ret = stack_push(s, &s2);
	printf("2. %d\n", ret);

	ret = stack_push(s, &s3);
	printf("2. %d\n", ret);

	ret = stack_push(s, &s1);
	printf("4. %d\n", ret);

	ret = stack_top(s, &s3_2);
	printf("5. %d\n", ret);
	student_dump(&s3_2);

	ret = stack_pop(s, &s3_2);
	printf("6. %d\n", ret);
	student_dump(&s3_2);

	ret = stack_pop(s, &s2_2);
	printf("7. %d\n", ret);
	student_dump(&s2_2);

	ret = stack_pop(s, &s1_2);
	printf("8. %d\n", ret);
	student_dump(&s1_2);

	ret = stack_pop(s, &s1_2);
	printf("9. %d\n", ret);

	ret = stack_top(s, &s1_2);
	printf("10. %d\n", ret);

	stack_destory(s);

	return 0;
}

char *student_dump(student * s)
{
	printf("%s: %d\n", s->name, s->age);
}
