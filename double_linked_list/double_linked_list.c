#include <stdlib.h>
#include <string.h>

#include "double_linked_list.h"

ddl_node *ddl_init(int esize, int (*equal) (void *v1, void *v2))
{
	ddl_node *list;

	if ((list =
	     (ddl_node *) malloc(sizeof(ddl_node) +
				 sizeof(struct ddl_info))) == NULL) {
		return NULL;
	}

	ESIZE(list) = esize;
	EQUAL(list) = equal;

	list->prev = list->next = NULL;

	return list;
}

ddl_node *ddl_insert_before(ddl_node * list, void *target, void *value)
{
	int esize;

	ddl_node *prev;
	ddl_node *this;
	ddl_node *new_node;

	for (this = list->next; this != NULL;
	     prev = this, this = this->next) {
		if (EQUAL(list) (this->buf, target)) {
			break;
		}
	}

	/* 没有找到 target */
	if (NULL == this) {
		return NULL;
	}

	/* 分配内存失败 */
	if ((new_node =
	     (ddl_node *) malloc(sizeof(ddl_node) +
				 ESIZE(list))) == NULL) {
		return NULL;
	}
	memcpy(new_node->buf, value, ESIZE(list));

	new_node->next = this;
	new_node->prev = prev == list ? NULL : prev;

	this->prev = new_node;
	prev->next = new_node;

	return new_node;
}

ddl_node *ddl_insert_after(ddl_node * list, void *target, void *value)
{
	int esize;

	ddl_node *this;
	ddl_node *next;
	ddl_node *new_node;

	for (this = list->next; this != NULL;
	     next = this, this = this->next) {
		if (EQUAL(list) (this->buf, target)) {
			break;
		}
	}

	/* 没有找到 target */
	if (NULL == this) {
		return NULL;
	}

	if ((new_node =
	     (ddl_node *) malloc(sizeof(ddl_node) +
				 ESIZE(list))) == NULL) {
		return NULL;
	}
	memcpy(new_node->buf, value, ESIZE(list));

	new_node->prev = this;
	new_node->next = next;

	this->next = new_node;
	/* this 是否最后一个元素 */
	(NULL == next ? list : next)->prev = new_node;

	return new_node;
}

ddl_node *ddl_insert_head(ddl_node * list, void *value)
{
	ddl_node *new_node;

	if ((new_node =
	     (ddl_node *) malloc(sizeof(ddl_node) + ESIZE(list))) ==
	    NULL) {
		return NULL;
	}
	memcpy(new_node->buf, value, ESIZE(list));

	new_node->prev = NULL;
	new_node->next = list->next;

	list->next = new_node;
	(list->prev == NULL ? list : new_node->next)->prev = new_node;

	return 0;
}

ddl_node *ddl_insert_tail(ddl_node * list, void *value)
{
	ddl_node *new_node;

	if ((new_node =
	     (ddl_node *) malloc(sizeof(ddl_node) + ESIZE(list))) ==
	    NULL) {
		return NULL;
	}
	memcpy(new_node->buf, value, ESIZE(list));

	new_node->prev = list->prev;
	new_node->next = NULL;

	list->prev = new_node;
	(list->next == NULL ? list : new_node->prev)->next = new_node;

	return 0;
}

ddl_node *ddl_del(ddl_node * list, void *target)
{
}
