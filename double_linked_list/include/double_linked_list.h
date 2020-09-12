#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

struct ddl_info {
	int size;
	int esize;
	int (*equal) (void *v1, void *v2);
};

#define ESIZE(list) (((struct ddl_info *) list->buf)->esize)
#define EQUAL(list) (((struct ddl_info *) list->buf)->equal)

typedef struct ddl_node {
	struct ddl_node *prev;
	struct ddl_node *next;
	unsigned char buf[0];
} ddl_node;

ddl_node *dll_init(int esize, int (*equal) (void *v1, void *v2));
ddl_node *dll_insert_head(ddl_node *list, void *value);
ddl_node *dll_insert_tail(ddl_node *list, void *value);

#endif
