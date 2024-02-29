#include "binary_trees.h"


/**
 * binary_tree_depth - Get the level of a root of a pruesomable, sub tree
 * @tree: Pointer to the root node
 * Return: Level number
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

