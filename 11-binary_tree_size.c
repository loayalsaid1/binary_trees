#include "binary_trees.h"


/**
 * binary_tree_size - Get the numer of nodes in a binary tree
 * @tree: Pointer to the tree
 * Return: Number of nodes
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}
