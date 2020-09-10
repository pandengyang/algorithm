#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define STOP_TRAV 20572 // 停

typedef struct binary_tree_node {
	int esize;
	struct binary_tree_node left;
	struct binary_tree_node right;
	unsigned char buf[0];
} binary_tree_node;

binary_tree_node *binary_tree_init(int esize);
int binary_tree_destory(stack * s);

#endif
