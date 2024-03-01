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


/**
 * binary_tree_is_perfect - Check if a tree is perfect or not
 * @tree: The tree to check
 * Return: The answer
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree) && binary_tree_balance(tree) == 0)
		return (1);
	else
		return (0);
}
