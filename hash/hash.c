#include <stdlib.h>
#include <string.h>

#include "double_linked_list.h"
#include "hash.h"

unsigned int hash_bkdr(char *key);
int entry_equal(void *e1, void *e2);

hash *hash_init(int size, int esize)
{
	hash *h;

	if ((h =
	     (hash *) malloc(sizeof(hash) + size * sizeof(ddl_node *))) ==
	    NULL) {
		return NULL;
	}

	h->size = size;
	h->esize = esize;
	for (int i = 0; i < size; i++) {
		h->buf[i] = NULL;
	}

	return h;
}

int hash_destroy(hash *h)
{
	for (int i = 0; i < h->size; i++) {
		if (NULL != h->buf[i]) {
			ddl_destroy(h->buf[i]);
		}
	}

	free(h);

	return 0;
}

int hash_set(hash * h, char *key, void *value)
{
	int index;
	ddl_node *node;
	unsigned char entry[sizeof (entry) + h->esize];

	index = hash_bkdr(key) % h->size;
	if (NULL == h->buf[index]) {
		if ((h->buf[index] =
		     ddl_init(sizeof(entry) + h->esize,
			      entry_equal)) == NULL) {
			return -1;
		}
	}

	/* 该 key 已存在 */
	node = ddl_find(h->buf[index], key);
	if (NULL != node) {
		memcpy(node->buf + KEY_LEN, value, h->esize);

		return 0;
	}

	/* 该 key 不存在 */
	strncpy(entry, key, KEY_LEN);
	memcpy(entry + KEY_LEN, value, h->esize);

	if (NULL == ddl_insert_head(h->buf[index], entry)) {
		return -1;
	}

	return 0;
}

int hash_get(hash * h, char *key, void *value)
{
	int index;
	ddl_node *node;

	index = hash_bkdr(key) % h->size;
	if (NULL == h->buf[index]) {
		return -1;
	}

	node = ddl_find(h->buf[index], key);
	if (NULL == node) {
		return -1;
	}

	memcpy(value, node->buf + KEY_LEN, h->esize);

	return 0;
}

int hash_del(hash * h, char *key)
{
	int index;
	ddl_node *node;

	index = hash_bkdr(key) % h->size;
	if (NULL == h->buf[index]) {
		return -1;
	}

	node = ddl_find(h->buf[index], key);
	if (NULL == node) {
		return -1;
	}

	return ddl_del(h->buf[index], key);
}

unsigned int hash_bkdr(char *key)
{
	unsigned int seed = 131;	// 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*key) {
		hash = hash * seed + (*key++);
	}

	return (hash & 0x7FFFFFFF);
}

int entry_equal(void *e1, void *key2)
{
	entry *en1 = (entry *) e1;

	return !strcmp(en1->key, (char *) key2);
}
