#include "binary_trees.h"


/**
 * get_root - Get the root node of a tree using a node in it
 * @node: A node to trace back it's root node
 * Return: The root node
*/
binary_tree_t *get_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return ((binary_tree_t *)node);

	return (get_root(node->parent));
}


/**
 * get_LCA - Get the LCA of a tree
 * @root: The root of the tree
 * @n1: Node 1
 * @n2: Node 2
 * Return: the LCA if found
*/
binary_tree_t *get_LCA(binary_tree_t *root,
	const binary_tree_t *n1, const binary_tree_t *n2)
{
	binary_tree_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (root == n1 || root == n2)
		return (root);

	left = get_LCA(root->left, n1, n2);
	right = get_LCA(root->right, n1, n2);

	if (left && right)
		return (root);

	if (left)
		return (left);
	else
		return (right);
}




/**
 * binary_trees_ancestor - Get the lowest common ancestor of 2 nodes
 * in a binary tree
 * @first: First node
 * @second: The second ndde
 * Return: The LCA
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *root = get_root(first);

	if (first == NULL || second == NULL || root == NULL)
		return (NULL);


	return (get_LCA(root, first, second));
}
