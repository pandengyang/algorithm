#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"

typedef struct {
	char name[16];
	int age;
} student;

void student_dump(student * s);
int student_comp(void *e1, void *e2);

int main(int argc, char **argv)
{
	int ret;

	student s1 = { "xiaohong", 6 };
	student s2 = { "xiaoming", 1 };
	student s3 = { "xiaoyou", 7 };
	student s4 = { "xiaoyou", 8 };
	student s5 = { "xiaoyou", 9 };
	student s6 = { "xiaoyou", 3 };
	student s7 = { "xiaoyou", 5 };
	student s8 = { "xiaoyou", 4 };
	student s9 = { "xiaoyou", 2 };

	student students[] = { s1, s2, s3, s4, s5, s6, s7, s8, s9 };

	ret =
	    array_insertion_sort(students,
			      sizeof students / sizeof students[0],
			      sizeof students[0], student_comp);

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
