#include "binary_trees.h"

/**
 * binary_tree_is_root - Check whether a node is root
 * @node: The node to examine.
 * Return: 1 if it's root, 0 otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && node->parent == NULL)
		return (1);
	else
		return (0);
}
