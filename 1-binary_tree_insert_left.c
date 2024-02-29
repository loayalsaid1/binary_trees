#include "binary_trees.h"


/**
 * binary_tree_insert_left - insert a node to hte left of the <parent>
 * @parent: The parent of node
 * @value: The value you feed the node
 * Return: A pointer to the node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);


	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left = node;
	}
	else
		node->left = NULL;

	return (node);
}
