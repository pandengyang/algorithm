#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

struct ddl_info {
	int esize;
	int (*equal) (void *e1, void *e2);
};

#define ESIZE(list) (((struct ddl_info *) list->buf)->esize)
#define EQUAL(list) (((struct ddl_info *) list->buf)->equal)

typedef struct ddl_node {
	struct ddl_node *prev;
	struct ddl_node *next;
	unsigned char buf[0];
} ddl_node;

ddl_node *dll_init(int esize, int (*equal) (void *e1, void *e2));
int ddl_destroy(ddl_node *list);
ddl_node *ddl_insert_before(ddl_node * list, void *target, void *element);
ddl_node *ddl_insert_after(ddl_node * list, void *target, void *element);
ddl_node *ddl_insert_head(ddl_node * list, void *element);
ddl_node *ddl_insert_tail(ddl_node * list, void *element);
int ddl_del(ddl_node * list, void *target);
int ddl_trav(ddl_node * list, int (*visit)(void *element));
ddl_node *ddl_find(ddl_node * list, void *target);

#endif
