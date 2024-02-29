#include "binary_trees.h"


/**
 * binary_tree_is_leaf - Check if a node is a leaf or not
 * @node: The node to examine
 * Return: 1 if a leaf, 0 otherwise
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
