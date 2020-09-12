#include <stdio.h>
#include <stdlib.h>

#include "bubble_sort.h"

typedef struct {
	char name[16];
	int age;
} student;

void student_dump(student * s);
int student_comp(void *e1, void *e2);

int main(int argc, char **argv)
{
	int ret;

	student s1 = { "xiaohong", 16 };
	student s2 = { "xiaoming", 17 };
	student s3 = { "xiaoyou", 18 };

	student students[] = { s2, s3, s1 };

	ret =
	    array_bubble_sort(students,
			      sizeof students / sizeof students[0],
			      sizeof students[0], student_comp);
	printf("1. %d\n", ret);

	for (int i = 0; i < sizeof students / sizeof students[0]; i++) {
		student_dump(students + i);
	}
}

int student_comp(void *e1, void *e2)
{
	student *s1 = (student *) e1;
	student *s2 = (student *) e2;

	return s1->age - s2->age;
}

void student_dump(student * s)
{
	printf("%s: %d\n", s->name, s->age);
}
