#include "binary_trees.h"


/**
 * binary_tree_preorder - Traverse a binary tree using the preorder
 * approach
 * @tree: The tree to traverse
 * @func: A function to run using the value in each node
 * Return: void
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
