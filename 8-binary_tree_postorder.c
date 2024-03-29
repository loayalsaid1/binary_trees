#include "binary_trees.h"


/**
 * binary_tree_postorder - Traverse a binary tree using the post-order
 * approach
 * @tree: The tree to traverse
 * @func: A function to run using the value in each node
 * Return: void
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
