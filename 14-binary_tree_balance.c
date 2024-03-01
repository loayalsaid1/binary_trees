#include "binary_trees.h"



/**
 * binary_tree_balance - Get the balance factor or a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The difference between the max height of left
 * subtree and right one
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int  left_max_height, right_max_height;

	if (tree == NULL)
		return (0);

	left_max_height = binary_tree_height(tree->left);
	right_max_height = binary_tree_height(tree->right);

	return (left_max_height - right_max_height);
}

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

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}
