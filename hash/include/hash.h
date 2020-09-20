#ifndef __HASH_H__
#define __HASH_H__

#include "double_linked_list.h"

typedef struct {
	int size;
	int esize;
	ddl_node *buf[0];
} hash;

typedef struct {
	char *key;
	unsigned char buf[0];
} entry;

hash *hash_init(int size, int esize);
int hash_set(hash * h, char *key, void *value);
int hash_get(hash * h, char *key, void *value);
int hash_del(hash * h, char *key);

#endif
