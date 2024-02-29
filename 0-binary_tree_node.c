#include "binary_trees.h"


/**
 * binary_tree_node - Create a node
 * @parent: The parent
 * @value: The value that the node will have
 * Return: Pointer to the created node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

