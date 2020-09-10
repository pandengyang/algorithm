#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

binary_tree_node *bt_init(int esize)
{
	binary_tree_node *tree;

	if ((tree =
	     (binary_tree_node *) malloc(sizeof(binary_tree_node) +
					 esize)) == NULL) {
		return NULL;
	}

	tree->esize = esize;
	tree->left = tree->right = NULL;

	return tree;
}

/* 前序遍历 */
int bt_pre_trav(binary_tree_node * tree, int (*visit) (void *value))
{
	if (NULL == tree) {
		return 0;
	}

	if (visit(tree.buf) == STOP_TRAV) {
		return STOP_TRAV;
	}

	if (bt_pre_trav(tree->left) == STOP_TRAV) {
		return STOP_TRAV;
	};

	if (bt_pre_trav(tree->right) == STOP_TRAV) {
		return STOP_TRAV;
	};

	return 0;
}

/* 中序遍历 */
int bt_in_trav(binary_tree_node * tree, int (*visit) (void *value))
{
}

/* 后序遍历 */
int bt_post_trav(binary_tree_node * tree, int (*visit) (void *value))
{
}
