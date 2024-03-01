#include "binary_trees.h"


/**
 * binary_tree_is_full - Check if all the tree is full or not
 * @tree: Pointer to the tree to examine
 * Return: 1 if it's full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_result, right_result;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_result = binary_tree_is_full(tree->left);
	right_result = binary_tree_is_full(tree->right);

	if (left_result == right_result)
		return (1);
	else
		return (0);
}
