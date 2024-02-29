#include "binary_trees.h"


/**
 * binary_tree_insert_right - Insert a node a tht eright an another node
 * @parent: The parent node
 * @value: The value to feed the node
 * Return: Pointer to the new node.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
	}
	else
		node->right = NULL;

	parent->right = node;

	return (node);
}
