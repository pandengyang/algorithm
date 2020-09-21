#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithm.h"
#include "double_linked_list.h"

typedef struct {
	char name[16];
	int age;
} student;

int student_equal(void *e1, void *e2);
int student_dump(void *e);

int main(int argc, char **argv)
{
	ddl_node *list;

	int ret;
	student s1 = { "xiaohong", 16 };
	student s2 = { "xiaoming", 17 };
	student s3 = { "xiaoyou", 18 };
	ddl_node *found;

	if ((list = ddl_init(sizeof(student), student_equal)) == NULL) {
		printf("ddl_init error");
		return -1;
	}

	ddl_insert_head(list, &s1);
	ddl_trav(list, student_dump);
	puts("");

	ddl_insert_head(list, &s2);
	ddl_trav(list, student_dump);
	puts("");

	ddl_insert_tail(list, &s3);
	ddl_trav(list, student_dump);
	puts("");

	ddl_insert_tail(list, &s2);
	ddl_trav(list, student_dump);
	puts("");

	ddl_insert_before(list, &s2, &s1);
	ddl_trav(list, student_dump);
	puts("");

	ddl_insert_after(list, &s1, &s3);
	ddl_trav(list, student_dump);
	puts("");

	ddl_del(list, &s1);
	ddl_trav(list, student_dump);
	puts("");

	found = ddl_find(list, &s1);
	if (found != NULL) {
		student_dump((void *) (found->buf));
	} else {
		puts("found is NULL");
	}
	puts("");

	ddl_destroy(list);

	return 0;
}

int student_dump(void *e)
{
	student *s = (struct student *) e;

	printf("--%s--", s->name);

	/*
	   if (!strcmp(s->name, "xiaohong")) {
	   return STOP_TRAV;
	   }
	 */

	return 0;
}

int student_equal(void *e1, void *e2)
{
	student *s1 = (struct student *) e1;
	student *s2 = (struct student *) e2;

	return !strcmp(s1->name, s2->name);
}
