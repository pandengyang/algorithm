#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "double_linked_list.h"

typedef struct {
	char name[16];
	int age;
} student;

int student_equal(void *e1, void *v2);
void student_dump(student * s);

int main(int argc, char **argv)
{
	ddl_node *list;

	int ret;
	student s1 = { "xiaohong", 16 };
	student s2 = { "xiaoming", 17 };
	student s3 = { "xiaoyou", 18 };

	if ((list = ddl_init(sizeof(student), student_equal)) == NULL) {
		printf("ddl_init error");
		return -1;
	}

	ddl_insert_head(list, &s1);

	return 0;
}

void student_dump(student * s)
{
	printf("%s\n", s->name);
}

int student_equal(void *e1, void *e2)
{
	student *s1 = (struct student *) e1;
	student *s2 = (struct student *) e2;

	return !strcmp(s1->name, s2->name);
}
