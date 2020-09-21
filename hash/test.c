#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "double_linked_list.h"
#include "hash.h"

typedef struct {
	char name[16];
	int age;
} student;

int student_equal(void *e1, void *e2);
int student_dump(void *e);

int main(int argc, char **argv)
{
	hash *h;

	int ret;
	student s1 = { "xiaohong", 16 };
	student s2 = { "xiaoming", 17 };
	student s3 = { "xiaoyou", 18 };
	student s4;

	if ((h = hash_init(5, sizeof(student))) == NULL) {
		printf("hash_init error");
		return -1;
	}

	ret = hash_set(h, "xiaohong", &s1);
	printf("1. %d\n", ret);

	ret = hash_set(h, "xiaoming", &s2);
	printf("2. %d\n", ret);

	ret = hash_get(h, "xiaoming", &s4);
	printf("3. %d\n", ret);
	student_dump(&s4);

	ret = hash_get(h, "xiaohong", &s4);
	printf("4. %d\n", ret);
	student_dump(&s4);

	ret = hash_get(h, "xiaozhang", &s4);
	printf("4. %d\n", ret);

	ret = hash_set(h, "xiaoming", &s1);
	printf("5. %d\n", ret);

	ret = hash_get(h, "xiaoming", &s4);
	printf("6. %d\n", ret);
	student_dump(&s4);

	ret = hash_del(h, "xiaohong");
	printf("7. %d\n", ret);

	ret = hash_del(h, "xiaohong");
	printf("8. %d\n", ret);

	ret = hash_get(h, "xiaohong", &s4);
	printf("9. %d\n", ret);

	ret = hash_get(h, "xiaoming", &s4);
	printf("10. %d\n", ret);
	student_dump(&s4);

	hash_destroy(h);

	return 0;
}

int student_dump(void *e)
{
	student *s = (student *) e;

	printf("--%s--\n", s->name);
}
