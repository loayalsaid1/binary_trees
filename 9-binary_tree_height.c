#include "binary_trees.h"


/**
 * binary_tree_height - Get the height of the tree
 * description: Get the max height of the tree execluding the root node
 *
 * @tree: The tree to examine
 * Return: The number of nodes
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (1 + left_height);
	else
		return ls(1 + right_height);
}
